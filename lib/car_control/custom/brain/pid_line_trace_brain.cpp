#include "pid_line_trace_brain.h"
#include "custom/instructions.h"
#include "ArduinoLog.h"

PidLineTraceBrain::PidLineTraceBrain(
        TraceMode trace_mode,
        int start_up_speed,
        unsigned long start_up_duration,
        int base_speed,
        int turn_speed,
        float p,
        float d,
        float back_p,
        float back_d,
        int lr_sensor_diff,
        int max_manipulation
) {
    this->trace_mode_ = trace_mode;
    this->start_up_speed_ = start_up_speed;
    this->start_up_duration_ = start_up_duration;
    this->base_speed_ = base_speed;
    this->turn_speed_ = turn_speed;
    this->p_ = p;
    this->d_ = d;
    this->back_p_ = back_p;
    this->back_d_ = back_d;
    this->lr_sensor_diff_ = lr_sensor_diff;
    this->max_manipulation_ = max_manipulation;
}

Instruction *PidLineTraceBrain::Ready() {
    this->activity_state_ = searching;
    last_time_called_ = millis();
    return new StartUpInstruction(start_up_speed_, base_speed_, start_up_duration_);
}

Instruction *PidLineTraceBrain::Search() {
    // 黒を発見するまで直進
    if (current_car_state_.IsAnyBlack()) {
        this->activity_state_ = tracing;
        return new StopInstruction(interrupt);
    }
    return new UpdateSpeedInstruction(base_speed_);
}

Instruction *PidLineTraceBrain::Trace() {

    // 全部白になったらトレース完了(継続トレースモードのときは完了しない）
    if (current_car_state_.IsAllWhite() && this->trace_mode_ != continuous) {
        this->activity_state_ = readyBack;
        return new StopInstruction(interrupt);
    }

    /**
     * deviation > 0 => 左の方が黒に近付いている
     * deviation < 0 => 右の方が黒に近付いている
     * この差分を用いて単純な比例制御を行う（P制御）
     */
    int deviation = current_car_state_.left_reflector_raw_ - current_car_state_.right_reflector_raw_ - lr_sensor_diff_;

    /**
     * 前に計算されたprev_deviation_と今回計算したdeviation、経過時間delta_timeを用いてdeviationの微分(deviation_differential)を計算する。
     * 計算された操作量を用いて微分制御を行う（D制御）
     */
    unsigned long delta_time = millis() - last_time_called_;
    float deviation_differential = (float) (deviation - prev_deviation_) / (float) delta_time;

    /**
     * 操作量の計算（PIDの各重みを考慮して最終的な操作量を計算する）
     */
    int manipulation = (int) (p_ * deviation + d_ * deviation_differential);

    // 操作量の範囲を制限
    manipulation = constrain(manipulation, -max_manipulation_, max_manipulation_);

    // deviationの上書きと時間更新（次回の準備）
    prev_deviation_ = deviation;
    last_time_called_ = millis();

    return new UpdateSpeedInstruction(base_speed_ - manipulation, base_speed_ + manipulation);
}

Instruction *PidLineTraceBrain::ReadyBack() {
    // タイヤの回転方向を切り替える
    this->activity_state_ = searchingBack;
    if (this->trace_mode_ == goBack) {
        // 前進・後退ならタイヤの回転方向を切り替える
        return new UpdateDirectionInstruction(backward);
    } else {
        // Uターンモードなら回転命令を出す
        return new TurnInstruction(turn_speed_, 100);
    }
}

Instruction *PidLineTraceBrain::SearchBack() {
    if (this->trace_mode_ == goBack) {
        if (this->current_car_state_.IsAnyBlack()) {
            this->activity_state_ = tracingBack;
            return new StopInstruction(interrupt);
        } else if (this->current_car_state_.left_wheel_speed_ == 0) {
//            return new StartUpInstruction(start_up_speed_, base_speed_, start_up_duration_);
            return new UpdateSpeedInstruction(base_speed_);
        } else {
            return new UpdateSpeedInstruction(base_speed_);
        }
    } else {
        if (this->current_car_state_.mid_reflector_color_ == black) {
            this->activity_state_ = tracingBack;
            return new InitInstruction(0, 0, backward, backward, interrupt);
        }
        return new TurnInstruction(turn_speed_, 100);
    }
}

/**
 * バックのときは各数値（deviationなど）の意味合いが逆になるので注意
 */
Instruction *PidLineTraceBrain::TraceBack() {
    // 全部白になったらトレース完了
    if (current_car_state_.IsAllWhite()) {
        this->activity_state_ = finished;
        return new StopInstruction(interrupt);
    }

    /**
     * deviation > 0 => 右の方が黒に近付いている ←前進時と逆になってることに注意
     * deviation < 0 => 左の方が黒に近付いている ←前進時と逆になってることに注意
     * この差分を用いて単純な比例制御を行う（P制御）
     */
    int deviation = current_car_state_.left_reflector_raw_ - current_car_state_.right_reflector_raw_ - lr_sensor_diff_;

    /**
     * 前に計算されたprev_deviation_と今回計算したdeviation、経過時間delta_timeを用いてdeviationの微分(deviation_differential)を計算する。
     * 計算された操作量を用いて微分制御を行う（D制御）
     */
    unsigned long delta_time = millis() - last_time_called_;
    float deviation_differential = (float) (deviation - prev_deviation_) / (float) delta_time;

    /**
     * 操作量の計算（PIDの各重みを考慮して最終的な操作量を計算する）
     */
    int manipulation = (int) (back_p_ * deviation + back_d_ * deviation_differential);

    // 操作量の範囲を制限
    manipulation = constrain(manipulation, -max_manipulation_, max_manipulation_);

    // deviationの上書きと時間更新（次回の準備）
    prev_deviation_ = deviation;
    last_time_called_ = millis();

    return new UpdateSpeedInstruction(base_speed_ + manipulation, base_speed_ - manipulation);
}

Instruction *PidLineTraceBrain::Finish() {
    // do nothing...
    return new WaitInstruction(10);
}

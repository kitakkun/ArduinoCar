#include "pid_line_trace_brain.h"
#include "custom/instruction/force_speed_update_instruction.h"
#include "custom/instruction/update_direction_instruction.h"
#include "custom/instruction/wait_instruction.h"

Instruction *PidLineTraceBrain::Ready() {
    this->activity_state_ = searching;
    last_time_called_ = millis();
    return new ForceSpeedUpdateInstruction(0);
}

Instruction *PidLineTraceBrain::Search() {
    // 黒を発見するまで直進
    if (current_car_state_.IsAnyBlack()) {
        this->activity_state_ = tracing;
        return new ForceSpeedUpdateInstruction(0);
    }
    return new ForceSpeedUpdateInstruction(base_speed_);
}

Instruction *PidLineTraceBrain::Trace() {

    // 全部白になったらトレース完了
    if (current_car_state_.IsAllWhite()) {
        this->activity_state_ = readyBack;
        return new ForceSpeedUpdateInstruction(0);
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
    float deviation_differential = (float)(deviation - prev_deviation_) / (float)delta_time;

    /**
     * 操作量の計算（PIDの各重みを考慮して最終的な操作量を計算する）
     */
    int manipulation = (int)(p_ * deviation + d_ * deviation_differential);

    // 操作量の範囲を制限
    manipulation = constrain(manipulation, -max_manipulation_, max_manipulation_);

    // deviationの上書きと時間更新（次回の準備）
    prev_deviation_ = deviation;
    last_time_called_ = millis();
    
    return new ForceSpeedUpdateInstruction(base_speed_ - manipulation, base_speed_ + manipulation);
}

Instruction *PidLineTraceBrain::ReadyBack() {
    // タイヤの回転方向を切り替える
    this->activity_state_ = searchingBack;
    return new UpdateDirectionInstruction(forward);
}

Instruction *PidLineTraceBrain::SearchBack() {
    return nullptr;
}

/**
 * バックのときは各数値（deviationなど）の意味合いが逆になるので注意
 */
Instruction *PidLineTraceBrain::TraceBack() {
    // 全部白になったらトレース完了
    if (current_car_state_.IsAllWhite()) {
        this->activity_state_ = finished;
        return new ForceSpeedUpdateInstruction(0);
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
    float deviation_differential = (float)(deviation - prev_deviation_) / (float)delta_time;

    /**
     * 操作量の計算（PIDの各重みを考慮して最終的な操作量を計算する）
     */
    int manipulation = (int)(p_ * deviation + d_ * deviation_differential);

    // 操作量の範囲を制限
    manipulation = constrain(manipulation, -max_manipulation_, max_manipulation_);

    // deviationの上書きと時間更新（次回の準備）
    prev_deviation_ = deviation;
    last_time_called_ = millis();

    return new ForceSpeedUpdateInstruction(base_speed_ + manipulation, base_speed_ - manipulation);
}

Instruction *PidLineTraceBrain::Finish() {
    // do nothing...
    return new WaitInstruction(10);
}

PidLineTraceBrain::PidLineTraceBrain(int base_speed, float p, float d, int lr_sensor_diff, int max_manipulation) {
    this->base_speed_ = base_speed;
    this->p_ = p;
    this->d_ = d;
    this->lr_sensor_diff_ = lr_sensor_diff;
    this->max_manipulation_ = max_manipulation;
}

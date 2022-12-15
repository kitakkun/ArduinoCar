#include "pid_follow_controller.h"
#include <Arduino.h>

PidFollowController::PidFollowController(
        FollowCar *car,
        int base_speed,
        int lr_sensor_diff,
        int max_manipulation,
        float p_weight,
        float d_weight
) {
    this->car_ = car;
    this->base_speed_ = base_speed;
    this->lr_sensor_diff_ = lr_sensor_diff;
    this->max_manipulation_ = max_manipulation;
    this->p_weight_ = p_weight;
    this->d_weight_ = d_weight;
}

void PidFollowController::Operate() {
    this->Follow();
}

void PidFollowController::Follow() {
    /**
     * deviation > 0 => 右の方が前に出ている
     * deviation < 0 => 左の方が前に出ている
     * この差分を用いて単純な比例制御を行う（P制御）
     */    
    int deviation = this->car_->GetLeftSensor()->GetRawValue()
                    - this->car_->GetRightSensor()->GetRawValue()
                    - this->lr_sensor_diff_;

    /**
     * 前に計算されたprev_deviation_と今回計算したdeviation、経過時間delta_timeを用いてdeviationの微分(deviation_differential)を計算する。
     * 計算された操作量を用いて微分制御を行う（D制御）
     */
    unsigned long delta_time = millis() - this->last_time_called_;
    float deviation_differential = (float) (deviation - this->prev_deviation_) / (float) delta_time;

    /**
     * 操作量の計算（PIDの各重みを考慮して最終的な操作量を計算する）
     */
    int manipulation = (int) (this->p_weight_ * deviation + this->d_weight_ * deviation_differential);

    // 操作量の範囲を制限
    manipulation = constrain(manipulation, -this->max_manipulation_, this->max_manipulation_);

    // deviationの上書きと時間更新（次回の準備）
    this->prev_deviation_ = deviation;
    this->last_time_called_ = millis();

    // 反映
    this->car_->GetLeftMotor()->UpdateSpeed(this->base_speed_ + manipulation);
    this->car_->GetRightMotor()->UpdateSpeed(this->base_speed_ - manipulation);
}
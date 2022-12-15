#include "pid_follow_controller.h"
#include <Arduino.h>

PidFollowController::PidFollowController(
        FollowCar *car,
        int theta,
        int base_speed,
        int lr_sensor_diff,
        int max_manipulation_dist,
        int max_manipulation_dev,
        float p_weight_dist,
        float d_weight_dist,
        float p_weight_dev,
        float d_weight_dev
) {
    this->car_ = car;
    this->theta_ = theta;
    this->base_speed_ = base_speed;
    this->lr_sensor_diff_ = lr_sensor_diff;
    this->max_manipulation_dist_ = max_manipulation_dist;
    this->p_weight_dist_ = p_weight_dist;
    this->d_weight_dist_ = d_weight_dist;
    this->max_manipulation_dev_ = max_manipulation_dev;
    this->p_weight_dev_ = p_weight_dev;
    this->d_weight_dev_ = d_weight_dev;
}

void PidFollowController::Update() {
    this->car_->GetLeftSensor()->Update();
    this->car_->GetRightSensor()->Update();
}

void PidFollowController::Operate() {
    this->Follow();
}

void PidFollowController::Follow() {
    // base_speedについてのpd制御

    /**
     * distance (-theta) > 0 => トレース車との距離が遠い
     * distance (-theta) < 0 => トレース車との距離が近い
     * この差分を用いて単純な比例制御を行う（P制御）
    */
    int distance = (this->car_->GetLeftSensor()->GetRawValue()
                   + this->car_->GetRightSensor()->GetRawValue())
                   /2 - theta_;

    // D制御を行う
    unsigned long delta_time = millis() - this->last_time_called_;
    float distance_differential = (float) (distance - this->prev_distance_) / (float) delta_time;

    // 操作量の計算（PIDの各重みを考慮して最終的な操作量を計算する）
    int manipulation_dist = (int) (this->p_weight_dist_ * distance + this->d_weight_dist_ * distance_differential);

    // 操作量の範囲を制限
    manipulation_dist = constrain(manipulation_dist, -this->max_manipulation_dist_, this->max_manipulation_dist_);

    // base_speedを更新
    base_speed_ += manipulation_dist;


    // 左右の差分についてのpd制御
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
    float deviation_differential = (float) (deviation - this->prev_deviation_) / (float) delta_time;

    /**
     * 操作量の計算（PIDの各重みを考慮して最終的な操作量を計算する）
     */
    int manipulation_dev = (int) (this->p_weight_dev_ * deviation + this->d_weight_dev_ * deviation_differential);

    // 操作量の範囲を制限
    manipulation_dev = constrain(manipulation_dev, -this->max_manipulation_dev_, this->max_manipulation_dev_);

    // deviationの上書きと時間更新（次回の準備）
    this->prev_distance_ = distance;
    this->prev_deviation_ = deviation;
    this->last_time_called_ = millis();

    // 反映
    this->car_->GetLeftMotor()->UpdateSpeed(this->base_speed_ + manipulation_dev);
    this->car_->GetRightMotor()->UpdateSpeed(this->base_speed_ - manipulation_dev);
}
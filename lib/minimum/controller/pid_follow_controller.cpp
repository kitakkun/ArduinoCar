#include "pid_follow_controller.h"
#include <Arduino.h>

PidFollowController::PidFollowController(
    FollowCar *car,
    float base_distance,
    float min_distance,
    int base_speed,
    int lr_sensor_diff,
    int max_manipulation_dist,
    int max_manipulation_torque,
    float p_weight_dist,
    float d_weight_dist,
    float p_weight_torque,
    float d_weight_torque
) {
    this->car_ = car;
    this->base_distance_ = base_distance;
    this->min_distance_ = min_distance;
    this->base_speed_ = base_speed;
    this->lr_sensor_diff_ = lr_sensor_diff;
    this->max_manipulation_dist_ = max_manipulation_dist;
    this->max_manipulation_torque_ = max_manipulation_torque;
    this->p_weight_dist_ = p_weight_dist;
    this->d_weight_dist_ = d_weight_dist;
    this->p_weight_torque_ = p_weight_torque;
    this->d_weight_torque_ = d_weight_torque;
    this->sensor_updater_ = new SonicSensorUpdater(car->GetLeftSensor(), car->GetRightSensor());
}

void PidFollowController::Update() {
    this->sensor_updater_->Update();
}

void PidFollowController::Operate() {
    this->Follow();
}

void PidFollowController::Follow() {
    // base_speedについてのpd制御

    /**
     * distance (-base_distance) > 0 => トレース車との距離が遠い
     * distance (-base_distance) < 0 => トレース車との距離が近い
     * この差分を用いて単純な比例制御を行う（P制御）
    */
    float distance = (this->car_->GetLeftSensor()->GetRawValue()
                      + this->car_->GetRightSensor()->GetRawValue())
                     / 2 - base_distance_;

    // D制御を行う
    unsigned long delta_time = millis() - this->last_time_called_;
    float distance_differential = (float) (distance - this->prev_distance_) / (float) delta_time;

    // 操作量の計算（PIDの各重みを考慮して最終的な操作量を計算する）
    int manipulation_dist = (int) (this->p_weight_dist_ * distance + this->d_weight_dist_ * distance_differential);

    // 操作量の範囲を制限
    manipulation_dist = constrain(manipulation_dist, -this->max_manipulation_dist_, this->max_manipulation_dist_);

    // base_speedを更新
    int adjusted_base_speed = this->base_speed_ + manipulation_dist;


    // 左右の差分についてのpd制御
    /**
     * deviation > 0 => 右の方が前に出ている
     * deviation < 0 => 左の方が前に出ている
     * この差分を用いて単純な比例制御を行う（P制御）
     */
    float deviation = this->car_->GetLeftSensor()->GetRawValue()
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
    int manipulation_torque = (int) (this->p_weight_torque_ * deviation + this->d_weight_torque_ * deviation_differential);

    // 操作量の範囲を制限
    manipulation_torque = constrain(manipulation_torque, -this->max_manipulation_torque_, this->max_manipulation_torque_);

    // deviationの上書きと時間更新（次回の準備）
    this->prev_distance_ = distance;
    this->prev_deviation_ = deviation;
    this->last_time_called_ = millis();

    // 反映
    if (distance > this->min_distance_) {
        this->car_->GetLeftMotor()->UpdateSpeed(adjusted_base_speed + manipulation_torque);
        this->car_->GetRightMotor()->UpdateSpeed(adjusted_base_speed - manipulation_torque);
    } else {
        // ぶつからないように左右の微調整のみ行う
        this->car_->GetLeftMotor()->UpdateSpeed(manipulation_torque);
        this->car_->GetRightMotor()->UpdateSpeed(-manipulation_torque);
    }
}
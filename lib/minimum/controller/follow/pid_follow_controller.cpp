#include "pid_follow_controller.h"
#include <Arduino.h>

PidFollowController::PidFollowController(
    FollowCar *car,
    float base_distance,
    int base_speed,
    float lr_sensor_diff,
    int max_manipulation_dist,
    int max_manipulation_torque,
    PIDController *speed_pid_controller,
    PIDController *torque_pid_controller
) {
    this->car_ = car;
    this->base_distance_ = base_distance;
    this->base_speed_ = base_speed;
    this->lr_sensor_diff_ = lr_sensor_diff;
    this->max_manipulation_dist_ = max_manipulation_dist;
    this->max_manipulation_torque_ = max_manipulation_torque;
    this->sensor_updater_ = new SonicSensorUpdater(car->GetLeftSensor(), car->GetRightSensor());
    this->speed_pid_controller_ = speed_pid_controller;
    this->torque_pid_controller_ = torque_pid_controller;
}

void PidFollowController::Update() {
    this->sensor_updater_->Update();
    this->car_->GetCrashDetector()->Update();
}

void PidFollowController::Operate() {
    this->Follow();
}

void PidFollowController::Follow() {
    // base_speedについてのpd制御
    double actual_distance = (this->car_->GetLeftSensor()->GetRawValue() + this->car_->GetRightSensor()->GetRawValue()) / 2;
    double speed_manipulation = speed_pid_controller_->CalcManipulation(actual_distance, this->base_distance_);
    speed_manipulation = constrain(speed_manipulation, -this->max_manipulation_dist_, this->max_manipulation_dist_);
    int adjusted_base_speed = this->base_speed_ + speed_manipulation;

    // torque制御
    int torque_manipulation = this->torque_pid_controller_->CalcManipulation(
        this->car_->GetLeftSensor()->GetRawValue(),
        this->car_->GetRightSensor()->GetRawValue() + this->lr_sensor_diff_
    );

    // 操作量の範囲を制限
    torque_manipulation = constrain(torque_manipulation, -this->max_manipulation_torque_, this->max_manipulation_torque_);

    // 反映
    if (this->car_->GetCrashDetector()->IsLow()) {
        // ぶつからないように左右のトルク調整のみ行う
        this->car_->GetLeftMotor()->UpdateSpeed(torque_manipulation);
        this->car_->GetRightMotor()->UpdateSpeed(-torque_manipulation);
    } else {
        this->car_->GetLeftMotor()->UpdateSpeed(adjusted_base_speed + torque_manipulation);
        this->car_->GetRightMotor()->UpdateSpeed(adjusted_base_speed - torque_manipulation);
    }
}

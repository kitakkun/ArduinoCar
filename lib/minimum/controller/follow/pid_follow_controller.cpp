#include "pid_follow_controller.h"
#include <Arduino.h>

PidFollowController::PidFollowController(
    FollowCar *car,
    PIDController *speed_pid_controller,
    PIDController *torque_pid_controller,
    FollowParams params
) {
    this->car_ = car;
    this->speed_pid_controller_ = speed_pid_controller;
    this->torque_pid_controller_ = torque_pid_controller;
    this->sensor_updater_ = new SonicSensorUpdater(car->GetLeftSensor(), car->GetRightSensor());
    this->params_ = params;
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
    double speed_manipulation = speed_pid_controller_->CalcManipulation(actual_distance, params_.base_distance);
    speed_manipulation = constrain(
        speed_manipulation,
        -params_.speed_max_manipulation,
        params_.speed_max_manipulation
    );
    int adjusted_base_speed = params_.base_speed + speed_manipulation;

    // torque制御
    int torque_manipulation = this->torque_pid_controller_->CalcManipulation(
        this->car_->GetLeftSensor()->GetRawValue(),
        this->car_->GetRightSensor()->GetRawValue() + params_.lr_sensor_diff
    );

    // 操作量の範囲を制限
    torque_manipulation = constrain(
        torque_manipulation,
        -params_.torque_max_manipulation,
        params_.torque_max_manipulation
    );

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

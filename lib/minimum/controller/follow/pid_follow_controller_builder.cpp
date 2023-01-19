#include "pid_follow_controller_builder.h"

PidFollowControllerBuilder &PidFollowControllerBuilder::SetCar(FollowCar *car) {
    this->car_ = car;
    return *this;
}

PidFollowControllerBuilder &PidFollowControllerBuilder::SetBaseDistance(float base_distance) {
    this->params_.base_distance = base_distance;
    return *this;
}

PidFollowControllerBuilder &PidFollowControllerBuilder::SetBaseSpeed(int base_speed) {
    this->params_.base_speed = base_speed;
    return *this;
}

PidFollowControllerBuilder &PidFollowControllerBuilder::SetLRSensorDiff(float lr_sensor_diff) {
    this->params_.lr_sensor_diff = lr_sensor_diff;
    return *this;
}

PidFollowControllerBuilder &PidFollowControllerBuilder::SetSpeedMaxManipulation(int speed_max_manipulation) {
    this->params_.speed_max_manipulation = speed_max_manipulation;
    return *this;
}

PidFollowControllerBuilder &PidFollowControllerBuilder::SetTorqueMaxManipulation(int torque_max_manipulation) {
    this->params_.torque_max_manipulation = torque_max_manipulation;
    return *this;
}

PidFollowControllerBuilder &PidFollowControllerBuilder::SetSpeedPidController(PIDController *pid_controller) {
    this->speed_pid_controller_ = pid_controller;
    return *this;
}

PidFollowControllerBuilder &PidFollowControllerBuilder::SetTorquePidController(PIDController *pid_controller) {
    this->torque_pid_controller_ = pid_controller;
    return *this;
}

PidFollowController *PidFollowControllerBuilder::Build() {
    return new PidFollowController(
        this->car_,
        this->speed_pid_controller_,
        this->torque_pid_controller_,
        this->params_
    );
}

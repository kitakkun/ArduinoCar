#include "pid_follow_controller_builder.h"

PidFollowControllerBuilder &PidFollowControllerBuilder::SetCar(FollowCar *car) {
    this->car_ = car;
    return *this;
}

PidFollowControllerBuilder &PidFollowControllerBuilder::SetBaseDistance(float base_distance) {
    this->base_distance_ = base_distance;
    return *this;
}

PidFollowControllerBuilder &PidFollowControllerBuilder::SetBaseSpeed(int base_speed) {
    this->base_speed_ = base_speed;
    return *this;
}

PidFollowControllerBuilder &PidFollowControllerBuilder::SetLRSensorDiff(float lr_sensor_diff) {
    this->lr_sensor_diff_ = lr_sensor_diff;
    return *this;
}

PidFollowControllerBuilder &PidFollowControllerBuilder::SetDistanceMaxManipulation(int max_manipulation_dist) {
    this->max_manipulation_dist_ = max_manipulation_dist;
    return *this;
}

PidFollowControllerBuilder &PidFollowControllerBuilder::SetTorqueMaxManipulation(int max_manipulation_torque) {
    this->max_manipulation_torque_ = max_manipulation_torque;
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
        this->base_distance_,
        this->base_speed_,
        this->lr_sensor_diff_,
        this->max_manipulation_dist_,
        this->max_manipulation_torque_,
        this->speed_pid_controller_,
        this->torque_pid_controller_
    );
}

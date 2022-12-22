#include "pid_follow_controller_builder.h"

PidFollowControllerBuilder::PidFollowControllerBuilder() {
    this->car_ = nullptr;
}

PidFollowControllerBuilder& PidFollowControllerBuilder::SetCar(FollowCar *car) {
    this->car_ = car;
    return *this;
}

PidFollowControllerBuilder& PidFollowControllerBuilder::SetBaseDistance(int base_distance) {
    this->base_distance_ = base_distance;
    return *this;
}

PidFollowControllerBuilder& PidFollowControllerBuilder::SetBaseSpeed(int base_speed) {
    this->base_speed_ = base_speed;
    return *this;
}

PidFollowControllerBuilder& PidFollowControllerBuilder::SetLRSensorDiff(int lr_sensor_diff) {
    this->lr_sensor_diff_ = lr_sensor_diff;
    return *this;
}

PidFollowControllerBuilder& PidFollowControllerBuilder::SetDistanceMaxManipulation(int max_manipulation_dist) {
    this->max_manipulation_dist_ = max_manipulation_dist;
    return *this;
}

PidFollowControllerBuilder& PidFollowControllerBuilder::SetTorqueMaxManipulation(int max_manipulation_torque) {
    this->max_manipulation_torque_ = max_manipulation_torque;
    return *this;
}

PidFollowControllerBuilder& PidFollowControllerBuilder::SetDistancePWeight(float p_weight_dist) {
    this->p_weight_dist_ = p_weight_dist;
    return *this;
}

PidFollowControllerBuilder& PidFollowControllerBuilder::SetDistanceDWeight(float d_weight_dist) {
    this->d_weight_dist_ = d_weight_dist;
    return *this;
}

PidFollowControllerBuilder& PidFollowControllerBuilder::SetTorquePWeight(float p_weight_torque) {
    this->p_weight_torque_ = p_weight_torque;
    return *this;
}

PidFollowControllerBuilder& PidFollowControllerBuilder::SetTorqueDWeight(float d_weight_torque) {
    this->d_weight_torque_ = d_weight_torque;
    return *this;
}

PidFollowController *PidFollowControllerBuilder::Build() {
    if (this->car_ == nullptr) {
        // インスタンス生成できない状態ならnullptrを返す
        return nullptr;
    } else {
        return new PidFollowController(
            this->car_
        );
    }
}

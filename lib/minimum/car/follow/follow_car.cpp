#include "follow_car.h"


FollowCar::FollowCar(
    Motor *left_motor,
    Motor *right_motor,
    SonicSensor *left_sensor,
    SonicSensor *right_sensor,
    DigitalSensor *crash_detector
) {
    this->left_motor_ = left_motor;
    this->right_motor_ = right_motor;
    this->left_sensor_ = left_sensor;
    this->right_sensor_ = right_sensor;
    this->crash_detector_ = crash_detector;
}

Motor *FollowCar::GetLeftMotor() {
    return this->left_motor_;
}

Motor *FollowCar::GetRightMotor() {
    return this->right_motor_;
}

SonicSensor *FollowCar::GetLeftSensor() {
    return this->left_sensor_;
}

SonicSensor *FollowCar::GetRightSensor() {
    return this->right_sensor_;
}

DigitalSensor *FollowCar::GetCrashDetector() {
    return this->crash_detector_;
}

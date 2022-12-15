#include "follow_car.h"

/* TODO: 実装 */

FollowCar::FollowCar(
    Motor *left_motor,
    Motor *right_motor,
    Sensor *left_sensor,
    Sensor *right_sensor
) {
    this->left_motor_ = left_motor;
    this->right_motor_ = right_motor;
    this->left_sensor_ = left_sensor;
    this->right_sensor_ = right_sensor;
}

Motor *FollowCar::GetLeftMotor() {
    return this->left_motor_;
}

Motor *FollowCar::GetRightMotor() {
    return this->right_motor_;
}

Sensor *FollowCar::GetLeftSensor() {
    return this->left_sensor_;
}

Sensor *FollowCar::GetRightSensor() {
    return this->right_sensor_;
}
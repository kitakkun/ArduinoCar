#include "follow_car_builder.h"

FollowCarBuilder::FollowCarBuilder() {
    this->left_motor_ = nullptr;
    this->right_motor_ = nullptr;
    this->left_sensor_ = nullptr;
    this->right_senor_ = nullptr;
}

void FollowCarBuilder::SetLeftMotor(Motor *left_motor) {
    this->left_motor_ = left_motor;
}

void FollowCarBuilder::SetRightMotor(Motor *right_motor) {
    this->right_motor_ = right_motor;
}

void FollowCarBuilder::SetLeftSensor(SonicSensor *left_sensor) {
    this->left_sensor_ = left_sensor;
}

void FollowCarBuilder::SetRightSensor(SonicSensor *right_sensor) {
    this->right_senor_ = right_sensor;
}

FollowCar *FollowCarBuilder::Build() {
    if (this->left_motor_ == nullptr ||
        this->right_motor_ == nullptr ||
        this->left_sensor_ == nullptr ||
        this->right_senor_ == nullptr) {
        // インスタンス生成できない状態ならnullptrを返す
        return nullptr;
    } else {
        return new FollowCar(
            this->left_motor_,
            this->right_motor_,
            this->left_sensor_,
            this->right_senor_
        );
    }
}

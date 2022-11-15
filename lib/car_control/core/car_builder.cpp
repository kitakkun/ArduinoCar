#include "car_builder.h"

void CarBuilder::SetLeftWheel(WheelImpl *left_wheel) {
    this->left_wheel_ = left_wheel;
}

void CarBuilder::SetRightWheel(WheelImpl *right_wheel) {
    this->right_wheel_ = right_wheel;
}


WheelImpl *CarBuilder::GetLeftWheel() {
    return this->left_wheel_;
}

WheelImpl *CarBuilder::GetRightWheel() {
    return this->right_wheel_;
}

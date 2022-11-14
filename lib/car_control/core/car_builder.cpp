#include "car_builder.h"

void CarBuilder::SetLeftWheel(Wheel *left_wheel) {
    this->left_wheel_ = left_wheel;
}

void CarBuilder::SetRightWheel(Wheel *right_wheel) {
    this->right_wheel_ = right_wheel;
}


Wheel *CarBuilder::GetLeftWheel() {
    return this->left_wheel_;
}

Wheel *CarBuilder::GetRightWheel() {
    return this->right_wheel_;
}

#include "trace_car.h"

/* TODO: クラスの実装 */
TraceCar::TraceCar(
        Motor *left_motor,
        Motor *right_motor,
        PhotoReflector *mid_reflector,
        PhotoReflector *left_reflector,
        PhotoReflector *right_reflector
) {
    this->left_motor_ = left_motor;
    this->right_motor_ = right_motor;
    this->mid_reflector_ = mid_reflector;
    this->left_reflector_ = left_reflector;
    this->right_reflector_ = right_reflector;
}

Motor *TraceCar::GetLeftMotor() {
    return this->left_motor_;
}

Motor *TraceCar::GetRightMotor() {
    return this->right_motor_;
}

PhotoReflector *TraceCar::GetMidReflector() {
    return this->mid_reflector_;
}

PhotoReflector *TraceCar::GetLeftReflector() {
    return this->left_reflector_;
}

PhotoReflector *TraceCar::GetRightReflector() {
    return this->right_reflector_;
}

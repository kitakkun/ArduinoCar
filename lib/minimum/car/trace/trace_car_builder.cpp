#include "trace_car_builder.h"

TraceCarBuilder::TraceCarBuilder() {
    this->left_motor_ = nullptr;
    this->right_motor_ = nullptr;
    this->left_reflector_ = nullptr;
    this->mid_reflector_ = nullptr;
    this->right_reflector_ = nullptr;
}

TraceCarBuilder& TraceCarBuilder::SetLeftMotor(Motor *left_motor) {
    this->left_motor_ = left_motor;
    return *this;
}

TraceCarBuilder& TraceCarBuilder::SetRightMotor(Motor *right_motor) {
    this->right_motor_ = right_motor;
    return *this;
}

TraceCarBuilder& TraceCarBuilder::SetLeftReflector(PhotoReflector *left_reflector) {
    this->left_reflector_ = left_reflector;
    return *this;
}

TraceCarBuilder& TraceCarBuilder::SetMidReflector(PhotoReflector *mid_reflector) {
    this->mid_reflector_ = mid_reflector;
    return *this;
}

TraceCarBuilder& TraceCarBuilder::SetRightReflector(PhotoReflector *right_reflector) {
    this->right_reflector_ = right_reflector;
    return *this;
}

TraceCar *TraceCarBuilder::Build() {
    if (this->left_motor_ == nullptr ||
        this->right_motor_ == nullptr ||
        this->left_reflector_ == nullptr ||
        this->mid_reflector_ == nullptr ||
        this->right_reflector_ == nullptr) {
        // インスタンス生成できない状態ならnullptrを返す
        return nullptr;
    } else {
        return new TraceCar(
            this->left_motor_,
            this->right_motor_,
            this->left_reflector_,
            this->mid_reflector_,
            this->right_reflector_
        );
    }
}
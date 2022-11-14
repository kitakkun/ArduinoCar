#include "car.h"
#include "car_builder.h"
#include "ArduinoLog.h"

Car::Car(CarBuilder *builder) {
    this->brain_ = builder->GetBrain();
    this->left_wheel_ = builder->GetLeftWheel();
    this->right_wheel_ = builder->GetRightWheel();
    this->front_left_reflector_ = builder->GetFrontLeftReflector();
    this->front_right_reflector_ = builder->GetFrontRightReflector();
    this->front_mid_reflector_ = builder->GetFrontMidReflector();
    this->back_left_reflector_ = builder->GetBackLeftReflector();
    this->back_right_reflector_ = builder->GetBackRightReflector();
    this->back_mid_reflector_ = builder->GetBackMidReflector();
    this->instruction_ = nullptr;
}

// センサー情報を更新
void Car::UpdateSensors() {
    this->front_left_reflector_->Update();
    this->front_right_reflector_->Update();
    this->front_mid_reflector_->Update();
}

CarState Car::CollectCarState() {
    return {
            this->left_wheel_->Speed(),
            this->right_wheel_->Speed(),
            this->left_wheel_->Direction(),
            this->right_wheel_->Direction(),
            this->front_mid_reflector_->Value(),
            this->front_right_reflector_->Value(),
            this->front_left_reflector_->Value(),
            this->back_mid_reflector_->Value(),
            this->back_right_reflector_->Value(),
            this->back_left_reflector_->Value(),
            this->front_mid_reflector_->RawValue(),
            this->front_right_reflector_->RawValue(),
            this->front_left_reflector_->RawValue(),
            this->back_mid_reflector_->RawValue(),
            this->back_right_reflector_->RawValue(),
            this->back_left_reflector_->RawValue(),
    };
}

Instruction *Car::Think(CarState state) {
    return this->brain_->CalculateNextInstruction(state);
}

void Car::Act() {
    if (instruction_ == nullptr) { return; }
    this->instruction_->runCoroutine();
    if (this->instruction_->isDone()) {
        delete this->instruction_;
        this->instruction_ = nullptr;
    }
}

void Car::SetInstruction(Instruction *instruction) {
    if (instruction_ == nullptr) {
        instruction_ = instruction;
        instruction_->Setup(left_wheel_, right_wheel_);
    } else {
        delete instruction;
    }
}
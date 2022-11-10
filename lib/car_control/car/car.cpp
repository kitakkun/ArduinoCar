#include "car.h"
#include "car_builder.h"
#include "ArduinoLog.h"

Car::Car(CarBuilder *builder) {
    this->brain_ = builder->GetBrain();
    this->left_wheel_ = builder->GetLeftWheel();
    this->right_wheel_ = builder->GetRightWheel();
    this->left_reflector_ = builder->GetLeftReflector();
    this->right_reflector_ = builder->GetRightReflector();
    this->mid_reflector_ = builder->GetMidReflector();
    this->instruction_ = nullptr;
}

// センサー情報を更新
void Car::UpdateSensors() {
    this->left_reflector_->Update();
    this->right_reflector_->Update();
    this->mid_reflector_->Update();
}

CarState Car::CollectCarState() {
    return {
            this->left_wheel_->Speed(),
            this->right_wheel_->Speed(),
            this->left_wheel_->Direction(),
            this->right_wheel_->Direction(),
            this->mid_reflector_->Value(),
            this->right_reflector_->Value(),
            this->left_reflector_->Value(),
            this->mid_reflector_->RawValue(),
            this->right_reflector_->RawValue(),
            this->left_reflector_->RawValue(),
    };
}

Instruction *Car::Think(CarState state) {
    return this->brain_->CalculateNextInstruction(state);
}

void Car::Act() {
    if (instruction_ == nullptr) { return; }
    this->instruction_->runCoroutine();
    this->left_wheel_->Apply();
    this->right_wheel_->Apply();
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
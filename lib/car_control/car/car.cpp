#include "car.h"
#include "car_builder.h"

Car::Car(CarBuilder *builder) {
    this->brain_ = builder->GetBrain();
    this->left_wheel_ = builder->GetLeftWheel();
    this->right_wheel_ = builder->GetRightWheel();
    this->left_reflector_ = builder->GetLeftReflector();
    this->right_reflector_ = builder->GetRightReflector();
    this->front_reflector_ = builder->GetFrontReflector();
}

// センサー情報を更新
void Car::UpdateSensors() {
    this->left_reflector_->Update();
    this->right_reflector_->Update();
    this->front_reflector_->Update();
}

CarState Car::CollectCarState() {
    return {
        this->left_wheel_->Speed(),
        this->right_wheel_->Speed(),
        this->left_wheel_->Direction(),
        this->right_wheel_->Direction(),
        this->front_reflector_->Value(),
        this->right_reflector_->Value(),
        this->left_reflector_->Value(),
    };
}

Instruction *Car::Think(CarState state) {
    return this->brain_->CalculateNextInstruction(state);
}

void Car::Act() {
    this->instruction_->Run(this->left_wheel_, this->right_wheel_);
    delete this->instruction_;
}

void Car::SetInstruction(Instruction *instruction) {
    this->instruction_ = instruction;
}

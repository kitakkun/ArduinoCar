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

// 行動
void Car::Action() {
    // TODO: brain_に必要なデータを渡して次の行動を決定
}

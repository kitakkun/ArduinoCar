#include "car.h"

Car::Car(Brain *brain, Wheel *left_wheel, Wheel *right_wheel, PhotoReflector *left_reflector,
         PhotoReflector *right_reflector, PhotoReflector *front_reflector) {
    this->brain_ = brain;
    this->left_wheel_ = left_wheel;
    this->right_wheel_ = right_wheel;
    this->left_reflector_ = left_reflector;
    this->right_reflector_ = right_reflector;
    this->front_reflector_ = front_reflector;
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

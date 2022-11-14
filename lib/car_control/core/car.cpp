#include "car.h"

Car::Car(CarBuilder *builder) {
    this->left_wheel_ = builder->GetLeftWheel();
    this->right_wheel_ = builder->GetRightWheel();
}

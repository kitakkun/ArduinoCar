#include "car.h"

Car::Car(Brain *brain, Wheel *left_wheel, Wheel *right_wheel) {
    this->brain_ = brain;
    this->left_wheel_ = left_wheel;
    this->right_wheel_ = right_wheel;
}

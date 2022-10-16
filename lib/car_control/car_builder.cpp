#include "car_builder.h"
#include "car.h"

void CarBuilder::SetLeftWheel(Wheel *wheel) {
    this->left_wheel_ = wheel;
}

void CarBuilder::SetRightWheel(Wheel *wheel) {
    this->right_wheel_ = wheel;
}

void CarBuilder::SetLeftReflector(PhotoReflector *reflector) {
    this->left_reflector_ = reflector;
}

void CarBuilder::SetRightReflector(PhotoReflector *reflector) {
    this->right_reflector_ = reflector;
}

void CarBuilder::SetFrontReflector(PhotoReflector *reflector) {
    this->front_reflector_ = reflector;
}

void CarBuilder::SetBrain(Brain *brain) {
    this->brain_ = brain;
}

PhotoReflector *CarBuilder::GetRightReflector() {
    return this->right_reflector_;
}

Wheel *CarBuilder::GetLeftWheel() {
    return this->left_wheel_;
}

Brain *CarBuilder::GetBrain() {
    return this->brain_;
}

Wheel *CarBuilder::GetRightWheel() {
    return this->right_wheel_;
}

PhotoReflector *CarBuilder::GetLeftReflector() {
    return left_reflector_;
}

PhotoReflector *CarBuilder::GetFrontReflector() {
    return front_reflector_;
}

Car *CarBuilder::Build() {
    return new Car(this);
}



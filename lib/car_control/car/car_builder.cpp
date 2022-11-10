#include "car_builder.h"
#include "car.h"

void CarBuilder::SetLeftWheel(Wheel *wheel) {
    this->left_wheel_ = wheel;
}

void CarBuilder::SetRightWheel(Wheel *wheel) {
    this->right_wheel_ = wheel;
}

void CarBuilder::SetFrontLeftReflector(PhotoReflector *reflector) {
    this->front_left_reflector_ = reflector;
}

void CarBuilder::SetFrontRightReflector(PhotoReflector *reflector) {
    this->front_right_reflector_ = reflector;
}

void CarBuilder::SetFrontMidReflector(PhotoReflector *reflector) {
    this->front_mid_reflector_ = reflector;
}

void CarBuilder::SetBackLeftReflector(PhotoReflector *reflector) {
    this->back_left_reflector_ = reflector;
}

void CarBuilder::SetBackRightReflector(PhotoReflector *reflector) {
    this->back_right_reflector_ = reflector;
}

void CarBuilder::SetBackMidReflector(PhotoReflector *reflector) {
    this->back_mid_reflector_ = reflector;
}

void CarBuilder::SetBrain(Brain *brain) {
    this->brain_ = brain;
}

PhotoReflector *CarBuilder::GetFrontRightReflector() {
    return this->front_right_reflector_;
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

PhotoReflector *CarBuilder::GetFrontLeftReflector() {
    return front_left_reflector_;
}

PhotoReflector *CarBuilder::GetFrontMidReflector() {
    return front_mid_reflector_;
}

PhotoReflector *CarBuilder::GetBackLeftReflector() {
    return back_left_reflector_;
}

PhotoReflector *CarBuilder::GetBackRightReflector() {
    return back_right_reflector_;
}

PhotoReflector *CarBuilder::GetBackMidReflector() {
    return back_mid_reflector_;
}
Car *CarBuilder::Build() {
    return new Car(this);
}




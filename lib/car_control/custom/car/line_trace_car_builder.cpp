#include "line_trace_car_builder.h"
#include "custom/brain/line_trace_brain.h"

LineTraceCarBuilder& LineTraceCarBuilder::SetFrontLeftReflector(PhotoReflector *reflector) {
    this->front_left_reflector_ = reflector;
    return *this;
}

LineTraceCarBuilder& LineTraceCarBuilder::SetFrontRightReflector(PhotoReflector *reflector) {
    this->front_right_reflector_ = reflector;
    return *this;
}

LineTraceCarBuilder& LineTraceCarBuilder::SetFrontMidReflector(PhotoReflector *reflector) {
    this->front_mid_reflector_ = reflector;
    return *this;
}

LineTraceCarBuilder& LineTraceCarBuilder::SetBackLeftReflector(PhotoReflector *reflector) {
    this->back_left_reflector_ = reflector;
    return *this;
}

LineTraceCarBuilder& LineTraceCarBuilder::SetBackRightReflector(PhotoReflector *reflector) {
    this->back_right_reflector_ = reflector;
    return *this;
}

LineTraceCarBuilder& LineTraceCarBuilder::SetBackMidReflector(PhotoReflector *reflector) {
    this->back_mid_reflector_ = reflector;
    return *this;
}

PhotoReflector *LineTraceCarBuilder::GetFrontRightReflector() {
    return this->front_right_reflector_;
}

PhotoReflector *LineTraceCarBuilder::GetFrontLeftReflector() {
    return front_left_reflector_;
}

PhotoReflector *LineTraceCarBuilder::GetFrontMidReflector() {
    return front_mid_reflector_;
}

PhotoReflector *LineTraceCarBuilder::GetBackLeftReflector() {
    return back_left_reflector_;
}

PhotoReflector *LineTraceCarBuilder::GetBackRightReflector() {
    return back_right_reflector_;
}

PhotoReflector *LineTraceCarBuilder::GetBackMidReflector() {
    return back_mid_reflector_;
}

Car *LineTraceCarBuilder::Build() {
    return new LineTraceCar(this);
}

LineTraceBrain *LineTraceCarBuilder::GetBrain() {
    return this->brain_;
}

LineTraceCarBuilder& LineTraceCarBuilder::SetBrain(LineTraceBrain *brain) {
    this->brain_ = brain;
    return *this;
}

LineTraceCarBuilder& LineTraceCarBuilder::SetLeftWheel(Wheel *wheel) {
    this->left_wheel_ = wheel;
    return *this;
}

LineTraceCarBuilder& LineTraceCarBuilder::SetRightWheel(Wheel *wheel) {
    this->right_wheel_ = wheel;
    return *this;
}

Wheel *LineTraceCarBuilder::GetLeftWheel() {
    return this->left_wheel_;
}

Wheel *LineTraceCarBuilder::GetRightWheel() {
    return this->right_wheel_;
}



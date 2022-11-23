#include "line_trace_car_builder.h"
#include "custom/brain/line_trace_brain.h"

LineTraceCarBuilder& LineTraceCarBuilder::SetLeftReflector(PhotoReflector *reflector) {
    this->left_reflector_ = reflector;
    return *this;
}

LineTraceCarBuilder& LineTraceCarBuilder::SetRightReflector(PhotoReflector *reflector) {
    this->right_reflector_ = reflector;
    return *this;
}

LineTraceCarBuilder& LineTraceCarBuilder::SetMidReflector(PhotoReflector *reflector) {
    this->mid_reflector_ = reflector;
    return *this;
}

PhotoReflector *LineTraceCarBuilder::GetRightReflector() {
    return this->right_reflector_;
}

PhotoReflector *LineTraceCarBuilder::GetLeftReflector() {
    return left_reflector_;
}

PhotoReflector *LineTraceCarBuilder::GetMidReflector() {
    return mid_reflector_;
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



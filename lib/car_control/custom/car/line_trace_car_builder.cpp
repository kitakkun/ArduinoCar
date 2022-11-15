#include "line_trace_car_builder.h"
#include "custom/brain/line_trace_brain.h"

void LineTraceCarBuilder::SetFrontLeftReflector(PhotoReflector *reflector) {
    this->front_left_reflector_ = reflector;
}

void LineTraceCarBuilder::SetFrontRightReflector(PhotoReflector *reflector) {
    this->front_right_reflector_ = reflector;
}

void LineTraceCarBuilder::SetFrontMidReflector(PhotoReflector *reflector) {
    this->front_mid_reflector_ = reflector;
}

void LineTraceCarBuilder::SetBackLeftReflector(PhotoReflector *reflector) {
    this->back_left_reflector_ = reflector;
}

void LineTraceCarBuilder::SetBackRightReflector(PhotoReflector *reflector) {
    this->back_right_reflector_ = reflector;
}

void LineTraceCarBuilder::SetBackMidReflector(PhotoReflector *reflector) {
    this->back_mid_reflector_ = reflector;
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

void LineTraceCarBuilder::SetBrain(LineTraceBrain *brain) {
    this->brain_ = brain;
}

void LineTraceCarBuilder::SetLeftWheel(Wheel *wheel) {
    this->left_wheel_ = wheel;
}

void LineTraceCarBuilder::SetRightWheel(Wheel *wheel) {
    this->right_wheel_ = wheel;
}

Wheel *LineTraceCarBuilder::GetLeftWheel() {
    return this->left_wheel_;
}

Wheel *LineTraceCarBuilder::GetRightWheel() {
    return this->right_wheel_;
}



#include "line_trace_car_builder.h"
#include "custom/brain/line_trace_brain.h"

void LineTraceCarBuilder::SetFrontLeftReflector(PhotoReflectorImpl *reflector) {
    this->front_left_reflector_ = reflector;
}

void LineTraceCarBuilder::SetFrontRightReflector(PhotoReflectorImpl *reflector) {
    this->front_right_reflector_ = reflector;
}

void LineTraceCarBuilder::SetFrontMidReflector(PhotoReflectorImpl *reflector) {
    this->front_mid_reflector_ = reflector;
}

void LineTraceCarBuilder::SetBackLeftReflector(PhotoReflectorImpl *reflector) {
    this->back_left_reflector_ = reflector;
}

void LineTraceCarBuilder::SetBackRightReflector(PhotoReflectorImpl *reflector) {
    this->back_right_reflector_ = reflector;
}

void LineTraceCarBuilder::SetBackMidReflector(PhotoReflectorImpl *reflector) {
    this->back_mid_reflector_ = reflector;
}

PhotoReflectorImpl *LineTraceCarBuilder::GetFrontRightReflector() {
    return this->front_right_reflector_;
}

PhotoReflectorImpl *LineTraceCarBuilder::GetFrontLeftReflector() {
    return front_left_reflector_;
}

PhotoReflectorImpl *LineTraceCarBuilder::GetFrontMidReflector() {
    return front_mid_reflector_;
}

PhotoReflectorImpl *LineTraceCarBuilder::GetBackLeftReflector() {
    return back_left_reflector_;
}

PhotoReflectorImpl *LineTraceCarBuilder::GetBackRightReflector() {
    return back_right_reflector_;
}

PhotoReflectorImpl *LineTraceCarBuilder::GetBackMidReflector() {
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



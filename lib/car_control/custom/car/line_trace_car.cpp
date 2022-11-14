#include "line_trace_car.h"
#include "line_trace_car_state.h"

LineTraceCar::LineTraceCar(LineTraceCarBuilder *builder) : Car(builder) {
    this->front_mid_reflector_ = builder->GetFrontMidReflector();
    this->front_left_reflector_ = builder->GetFrontLeftReflector();
    this->front_right_reflector_ = builder->GetFrontRightReflector();
    this->back_mid_reflector_ = builder->GetBackMidReflector();
    this->back_left_reflector_ = builder->GetBackLeftReflector();
    this->back_right_reflector_ = builder->GetBackRightReflector();
}

void LineTraceCar::UpdateSensors() {
    this->front_mid_reflector_->Update();
    this->front_left_reflector_->Update();
    this->front_right_reflector_->Update();
    this->back_mid_reflector_->Update();
    this->back_left_reflector_->Update();
    this->back_right_reflector_->Update();
}

void LineTraceCar::Think() {
    brain_->SetCurrentCarState(CollectCarState());
    instruction_ = brain_->CalculateNextInstruction();
}

void LineTraceCar::Act() {
    if (this->instruction_ == nullptr) return;

    instruction_->runCoroutine();

    if (instruction_->isDone()) {
        delete instruction_;
        instruction_ = nullptr;
    }
}

LineTraceCarState LineTraceCar::CollectCarState() {
    return {
        left_wheel_->Speed(),
        right_wheel_->Speed(),
        left_wheel_->Direction(),
        right_wheel_->Direction(),
        front_mid_reflector_->Value(),
        front_left_reflector_->Value(),
        front_right_reflector_->Value(),
        back_mid_reflector_->Value(),
        back_left_reflector_->Value(),
        back_right_reflector_->Value(),
        front_mid_reflector_->RawValue(),
        front_left_reflector_->RawValue(),
        front_right_reflector_->RawValue(),
        back_mid_reflector_->RawValue(),
        back_left_reflector_->RawValue(),
        back_right_reflector_->RawValue(),
    };
}

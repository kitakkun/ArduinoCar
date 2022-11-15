#include "line_trace_car.h"
#include "custom/data_model/line_trace_car_state.h"

LineTraceCar::LineTraceCar(LineTraceCarBuilder *builder, String tag) : Car(builder), Debuggable(tag) {
    this->brain_ = builder->GetBrain();
    this->front_mid_reflector_ = builder->GetFrontMidReflector();
    this->front_left_reflector_ = builder->GetFrontLeftReflector();
    this->front_right_reflector_ = builder->GetFrontRightReflector();
    this->back_mid_reflector_ = builder->GetBackMidReflector();
    this->back_left_reflector_ = builder->GetBackLeftReflector();
    this->back_right_reflector_ = builder->GetBackRightReflector();
    this->instruction_ = nullptr;
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
    Instruction *instruction = brain_->CalculateNextInstruction();
    if (instruction_ == nullptr) {
        instruction_ = instruction;
        instruction_->Setup(left_wheel_, right_wheel_);
        return;
    }
    if (instruction->Mode() == interrupt) {
        instruction_->reset();
        delete instruction_;
        instruction_ = instruction;
        instruction_->Setup(left_wheel_, right_wheel_);
    } else {
        delete instruction;
    }
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

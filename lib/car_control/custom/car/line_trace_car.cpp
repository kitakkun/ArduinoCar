#include "line_trace_car.h"
#include "custom/data_model/line_trace_car_state.h"

LineTraceCar::LineTraceCar(LineTraceCarBuilder *builder, String tag) : Debuggable(tag) {
    this->brain_ = builder->GetBrain();
    this->left_wheel_ = builder->GetLeftWheel();
    this->right_wheel_ = builder->GetRightWheel();
    this->mid_reflector_ = builder->GetMidReflector();
    this->left_reflector_ = builder->GetLeftReflector();
    this->right_reflector_ = builder->GetRightReflector();
    this->instruction_ = nullptr;
}

void LineTraceCar::UpdateSensors() {
    this->mid_reflector_->Update();
    this->left_reflector_->Update();
    this->right_reflector_->Update();
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
            mid_reflector_->Value(),
            left_reflector_->Value(),
            right_reflector_->Value(),
            mid_reflector_->RawValue(),
            left_reflector_->RawValue(),
            right_reflector_->RawValue(),
    };
}

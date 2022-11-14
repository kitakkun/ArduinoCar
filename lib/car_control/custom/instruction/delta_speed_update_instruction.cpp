#include "delta_speed_update_instruction.h"

DeltaSpeedUpdateInstruction::DeltaSpeedUpdateInstruction(int amount) {
    this->l_amount_ = amount;
    this->r_amount_ = amount;
}

int DeltaSpeedUpdateInstruction::runCoroutine() {
    COROUTINE_BEGIN();
    left_wheel_->UpdateSpeed(left_wheel_->Speed() + l_amount_);
    right_wheel_->UpdateSpeed(right_wheel_->Speed() + r_amount_);
    COROUTINE_END();
}

DeltaSpeedUpdateInstruction::DeltaSpeedUpdateInstruction(int l_amount, int r_amount) {
    l_amount_ = l_amount;
    r_amount_ = r_amount;
}
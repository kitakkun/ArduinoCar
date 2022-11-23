#include "delta_speed_update_instruction.h"

DeltaSpeedUpdateInstruction::DeltaSpeedUpdateInstruction(int amount, InstructionMode mode) {
    this->l_amount_ = amount;
    this->r_amount_ = amount;
    this->mode_ = mode;
}

DeltaSpeedUpdateInstruction::DeltaSpeedUpdateInstruction(int l_amount, int r_amount, InstructionMode mode) {
    l_amount_ = l_amount;
    r_amount_ = r_amount;
    this->mode_ = mode;
}

int DeltaSpeedUpdateInstruction::Run(Wheel *left_wheel, Wheel *right_wheel) {
    COROUTINE_BEGIN()
    left_wheel->UpdateDeltaSpeed(l_amount_);
    right_wheel->UpdateDeltaSpeed(r_amount_);
    COROUTINE_END();
}

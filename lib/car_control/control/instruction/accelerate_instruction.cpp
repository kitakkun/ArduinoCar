#include "accelerate_instruction.h"

void AccelerateInstruction::Run(Wheel *left_wheel, Wheel *right_wheel) {
    left_wheel->Accelerate(this->amount_);
    right_wheel->Accelerate(this->amount_);
    left_wheel->Apply();
    right_wheel->Apply();
}

AccelerateInstruction::AccelerateInstruction(int amount) {
    this->amount_ = amount;
}

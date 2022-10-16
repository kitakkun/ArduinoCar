#include "decelerate_instruction.h"

DecelerateInstruction::DecelerateInstruction(int amount) {
    this->amount_ = amount;
}

void DecelerateInstruction::Run(Wheel *left_wheel, Wheel *right_wheel) {
    left_wheel->Decelerate(this->amount_);
    right_wheel->Decelerate(this->amount_);
    left_wheel->Apply();
    right_wheel->Apply();
}

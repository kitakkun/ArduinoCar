#include "accelerate_instruction.h"

AccelerateInstruction::AccelerateInstruction(int amount) {
    this->amount_ = amount;
}

int AccelerateInstruction::runCoroutine() {
    left_wheel_->Accelerate(this->amount_);
    right_wheel_->Accelerate(this->amount_);
    left_wheel_->Apply();
    right_wheel_->Apply();
    return Instruction::runCoroutine();
}

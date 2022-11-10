#include "decelerate_instruction.h"

DecelerateInstruction::DecelerateInstruction(int amount) {
    this->amount_ = amount;
}

int DecelerateInstruction::runCoroutine() {
    COROUTINE_BEGIN();
    left_wheel_->Decelerate(this->amount_);
    right_wheel_->Decelerate(this->amount_);
    left_wheel_->Apply();
    right_wheel_->Apply();
    COROUTINE_END();
}

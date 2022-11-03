#include "torque_right_instruction.h"

TorqueRightInstruction::TorqueRightInstruction(int force) {
    this->force_ = force;
}

int TorqueRightInstruction::runCoroutine() {
    right_wheel_->UpdateSpeed(left_wheel_->Speed() - this->force_);
    return Instruction::runCoroutine();
}

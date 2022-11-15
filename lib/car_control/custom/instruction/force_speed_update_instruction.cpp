#include "force_speed_update_instruction.h"

ForceSpeedUpdateInstruction::ForceSpeedUpdateInstruction(int left_speed, int right_speed, InstructionMode mode) : Instruction(mode) {
    this->left_speed_ = left_speed;
    this->right_speed_ = right_speed;
}

int ForceSpeedUpdateInstruction::runCoroutine() {
    COROUTINE_BEGIN();
    left_wheel_->UpdateSpeed(this->left_speed_);
    right_wheel_->UpdateSpeed(this->right_speed_);
    COROUTINE_END();
}

ForceSpeedUpdateInstruction::ForceSpeedUpdateInstruction(int speed, InstructionMode mode) : Instruction(mode) {
    this->left_speed_ = speed;
    this->right_speed_ = speed;
}

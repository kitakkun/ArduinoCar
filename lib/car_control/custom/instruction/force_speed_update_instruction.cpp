#include "force_speed_update_instruction.h"

ForceSpeedUpdateInstruction::ForceSpeedUpdateInstruction(int left_speed, int right_speed, InstructionMode mode, String tag) {
    this->left_speed_ = left_speed;
    this->right_speed_ = right_speed;
}

ForceSpeedUpdateInstruction::ForceSpeedUpdateInstruction(int speed, InstructionMode mode, String tag) {
    this->left_speed_ = speed;
    this->right_speed_ = speed;
}

int ForceSpeedUpdateInstruction::Run(Wheel *left_wheel, Wheel *right_wheel) {
    COROUTINE_BEGIN();
    left_wheel->UpdateSpeed(this->left_speed_);
    right_wheel->UpdateSpeed(this->right_speed_);
    COROUTINE_END();
}

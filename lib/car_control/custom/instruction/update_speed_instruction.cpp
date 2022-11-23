#include "update_speed_instruction.h"

UpdateSpeedInstruction::UpdateSpeedInstruction(int left_speed, int right_speed, InstructionMode mode) {
    this->left_speed_ = left_speed;
    this->right_speed_ = right_speed;
    this->mode_ = mode;
}

UpdateSpeedInstruction::UpdateSpeedInstruction(int speed, InstructionMode mode) {
    this->left_speed_ = speed;
    this->right_speed_ = speed;
    this->mode_ = mode;
}

int UpdateSpeedInstruction::Run(Wheel *left_wheel, Wheel *right_wheel) {
    COROUTINE_BEGIN();
    left_wheel->UpdateSpeed(this->left_speed_);
    right_wheel->UpdateSpeed(this->right_speed_);
    COROUTINE_END();
}

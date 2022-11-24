#include "init_instruction.h"

int InitInstruction::Run(Wheel *left_wheel, Wheel *right_wheel) {
    COROUTINE_BEGIN();
    left_wheel->UpdateSpeed(this->left_speed_);
    left_wheel->UpdateDirection(this->left_direction_);
    right_wheel->UpdateSpeed(this->right_speed_);
    right_wheel->UpdateDirection(this->right_direction_);
    COROUTINE_END();
}

InitInstruction::InitInstruction(int left_speed, int right_speed, MoveDirection left_direction, MoveDirection right_direction, InstructionMode mode) {
    this->mode_ = mode;
    this->left_speed_ = left_speed;
    this->right_speed_ = right_speed;
    this->left_direction_ = left_direction;
    this->right_direction_ = right_direction;
}

#include "force_speed_update_instruction.h"

void ForceSpeedUpdateInstruction::Run(Wheel *left_wheel, Wheel *right_wheel) {
    left_wheel->UpdateSpeed(this->left_speed_);
    right_wheel->UpdateSpeed(this->right_speed_);
}

ForceSpeedUpdateInstruction::ForceSpeedUpdateInstruction(int left_speed, int right_speed) {
    this->left_speed_ = left_speed;
    this->right_speed_ = right_speed;
}

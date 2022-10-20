#include "torque_right_instruction.h"

void TorqueRightInstruction::Run(Wheel *left_wheel, Wheel *right_wheel){
    left_wheel->Decelerate(this->force_);
}

TorqueRightInstruction::TorqueRightInstruction(int force){
    this->force_ = force;
}

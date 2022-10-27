#include "torque_left_instruction.h"

void TorqueLeftInstruction::Run(Wheel *left_wheel, Wheel *right_wheel){
    left_wheel->UpdateSpeed(right_wheel->Speed() - this->force_);
}

TorqueLeftInstruction::TorqueLeftInstruction(int force){
    this->force_ = force;
}

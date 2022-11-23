#include "torque_right_instruction.h"
#include "ArduinoLog.h"

TorqueRightInstruction::TorqueRightInstruction(int base_speed, int force, InstructionMode mode) {
    this->base_speed_ = base_speed;
    this->force_ = force;
    this->mode_ = mode;
}

int TorqueRightInstruction::Run(Wheel *left_wheel, Wheel *right_wheel) {
    COROUTINE_BEGIN();
    if (left_wheel->Direction() == forward) {
        left_wheel->UpdateSpeed(base_speed_);
        right_wheel->UpdateSpeed(base_speed_ - force_);
    } else {
        left_wheel->UpdateSpeed(base_speed_ - force_);
        right_wheel->UpdateSpeed(base_speed_);
    }
    COROUTINE_END();
}

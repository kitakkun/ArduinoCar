#include "torque_left_instruction.h"
#include "ArduinoLog.h"
#include "core/debug/logger.h"

TorqueLeftInstruction::TorqueLeftInstruction(int base_speed, int force, InstructionMode mode, String tag) {
    base_speed_ = base_speed;
    force_ = force;
}

int TorqueLeftInstruction::Run(Wheel *left_wheel, Wheel *right_wheel) {
    COROUTINE_BEGIN();
    if (left_wheel->Direction() == forward) {
        left_wheel->UpdateSpeed(base_speed_ - force_);
        right_wheel->UpdateSpeed(base_speed_);
    } else {
        left_wheel->UpdateSpeed(base_speed_);
        right_wheel->UpdateSpeed(base_speed_ - force_);
    }
    COROUTINE_END();
}

#include "torque_left_instruction.h"
#include "ArduinoLog.h"
#include "core/debug/logger.h"

TorqueLeftInstruction::TorqueLeftInstruction(int base_speed, int force, InstructionMode mode, String tag)
        : InstructionImpl(mode, tag) {
    base_speed_ = base_speed;
    force_ = force;
}

int TorqueLeftInstruction::runCoroutine() {
    COROUTINE_BEGIN();
    if (left_wheel_->Direction() == forward) {
        left_wheel_->UpdateSpeed(base_speed_ - force_);
        right_wheel_->UpdateSpeed(base_speed_);
    } else {
        left_wheel_->UpdateSpeed(base_speed_);
        right_wheel_->UpdateSpeed(base_speed_ - force_);
    }
    COROUTINE_END();
}

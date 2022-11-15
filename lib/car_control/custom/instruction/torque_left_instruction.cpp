#include "torque_left_instruction.h"
#include "ArduinoLog.h"

TorqueLeftInstruction::TorqueLeftInstruction(
        int base_speed, int force, int duration_millis, InstructionMode mode, String tag
) : Instruction(mode, tag) {
    base_speed_ = base_speed;
    force_ = force;
    duration_millis_ = duration_millis;
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
    COROUTINE_DELAY(duration_millis_);
    left_wheel_->UpdateSpeed(base_speed_);
    right_wheel_->UpdateSpeed(base_speed_);
    COROUTINE_END();
}

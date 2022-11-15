#include "torque_right_instruction.h"
#include "ArduinoLog.h"

TorqueRightInstruction::TorqueRightInstruction(int base_speed, int force, int duration_millis, InstructionMode mode, String tag)
        : Instruction(mode, tag) {
    base_speed_ = base_speed;
    force_ = force;
    duration_millis_ = duration_millis;
}

int TorqueRightInstruction::runCoroutine() {
    COROUTINE_BEGIN();
    if (left_wheel_->Direction() == forward) {
        left_wheel_->UpdateSpeed(base_speed_);
        right_wheel_->UpdateSpeed(base_speed_ - force_);
    } else {
        left_wheel_->UpdateSpeed(base_speed_ - force_);
        right_wheel_->UpdateSpeed(base_speed_);
    }
    COROUTINE_DELAY(duration_millis_);
    left_wheel_->UpdateSpeed(base_speed_);
    right_wheel_->UpdateSpeed(base_speed_);
    COROUTINE_END();
}

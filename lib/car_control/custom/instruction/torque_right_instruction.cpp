#include "torque_right_instruction.h"
#include "ArduinoLog.h"

TorqueRightInstruction::TorqueRightInstruction(int base_speed, int force, int duration_millis, InstructionMode mode)
        : Instruction(mode) {
    base_speed_ = base_speed;
    force_ = force;
    duration_millis_ = duration_millis;
}

int TorqueRightInstruction::runCoroutine() {
    COROUTINE_BEGIN();
    left_wheel_->UpdateSpeed(base_speed_);
    right_wheel_->UpdateSpeed(base_speed_ - force_);
    COROUTINE_DELAY(duration_millis_);
    left_wheel_->UpdateSpeed(base_speed_);
    right_wheel_->UpdateSpeed(base_speed_);
    COROUTINE_END();
}

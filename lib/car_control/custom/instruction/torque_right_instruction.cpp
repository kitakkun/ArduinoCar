#include "torque_right_instruction.h"
#include "ArduinoLog.h"

TorqueRightInstruction::TorqueRightInstruction(int force, int duration_millis) {
    force_ = force;
    duration_millis_ = duration_millis;
}

int TorqueRightInstruction::runCoroutine() {
    COROUTINE_BEGIN();
    right_wheel_->UpdateSpeed(left_wheel_->Speed() - force_);
    COROUTINE_DELAY(duration_millis_);
    right_wheel_->UpdateSpeed(left_wheel_->Speed());
    COROUTINE_END();
}

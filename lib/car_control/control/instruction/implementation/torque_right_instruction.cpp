#include "torque_right_instruction.h"
#include "ArduinoLog.h"

TorqueRightInstruction::TorqueRightInstruction(int force, int duration_millis) {
    force_ = force;
    duration_millis_ = duration_millis;
}

int TorqueRightInstruction::runCoroutine() {
    COROUTINE_BEGIN();
    Log.verboseln("MOVING: RIGHT");
    right_wheel_->UpdateSpeed(left_wheel_->Speed() - force_);
    right_wheel_->Apply();
    COROUTINE_DELAY(duration_millis_);
    right_wheel_->UpdateSpeed(left_wheel_->Speed());
    right_wheel_->Apply();
    COROUTINE_END();
}

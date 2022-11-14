#include "torque_left_instruction.h"
#include "ArduinoLog.h"

TorqueLeftInstruction::TorqueLeftInstruction(int force, int duration_millis){
    force_ = force;
    duration_millis_ = duration_millis;
}

int TorqueLeftInstruction::runCoroutine() {
    COROUTINE_BEGIN();
    left_wheel_->UpdateSpeed(right_wheel_->Speed() - force_);
    COROUTINE_DELAY(duration_millis_);
    left_wheel_->UpdateSpeed(right_wheel_->Speed());
    COROUTINE_END();
}

#include "torque_left_instruction.h"
#include "ArduinoLog.h"

TorqueLeftInstruction::TorqueLeftInstruction(int base_speed, int force, int duration_millis){
    base_speed_ = base_speed;
    force_ = force;
    duration_millis_ = duration_millis;
}

int TorqueLeftInstruction::runCoroutine() {
    COROUTINE_BEGIN();
    left_wheel_->UpdateSpeed(base_speed_ - force_);
    right_wheel_->UpdateSpeed(base_speed_);
    COROUTINE_DELAY(duration_millis_);
    left_wheel_->UpdateSpeed(base_speed_);
    right_wheel_->UpdateSpeed(base_speed_);
    COROUTINE_END();
}

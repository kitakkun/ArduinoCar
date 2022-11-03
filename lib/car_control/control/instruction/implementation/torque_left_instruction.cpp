#include "torque_left_instruction.h"

TorqueLeftInstruction::TorqueLeftInstruction(int force, int duration_millis){
    force_ = force;
    duration_millis_ = duration_millis;
}

int TorqueLeftInstruction::runCoroutine() {
    COROUTINE_BEGIN();
    while (current_time_ < duration_millis_) {
        left_wheel_->UpdateSpeed(right_wheel_->Speed() - force_);
        current_time_ += 20;
        COROUTINE_DELAY(20);
    }
    COROUTINE_END();
}

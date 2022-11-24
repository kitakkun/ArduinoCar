#include "start_up_instruction.h"

StartUpInstruction::StartUpInstruction(int startup_speed, int base_speed, unsigned long duration_millis) {
    this->startup_speed_ = startup_speed;
    this->base_speed_ = base_speed;
    this->duration_millis_ = duration_millis;
}

int StartUpInstruction::Run(Wheel *left_wheel, Wheel *right_wheel) {
    COROUTINE_BEGIN();
    left_wheel->UpdateSpeed(startup_speed_);
    right_wheel->UpdateSpeed(startup_speed_);
    COROUTINE_DELAY(duration_millis_);
    left_wheel->UpdateSpeed(base_speed_);
    right_wheel->UpdateSpeed(base_speed_);
    COROUTINE_END();
}

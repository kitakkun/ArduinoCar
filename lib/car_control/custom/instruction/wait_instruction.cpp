#include "wait_instruction.h"

WaitInstruction::WaitInstruction(int duration_millis, InstructionMode mode) {
    this->duration_millis_ = duration_millis;
    this->mode_ = mode;
}

int WaitInstruction::Run(Wheel *left_wheel, Wheel *right_wheel) {
    COROUTINE_BEGIN();
    COROUTINE_DELAY(duration_millis_);
    COROUTINE_END();
}

#include "wait_instruction.h"

WaitInstruction::WaitInstruction(int duration_millis, InstructionMode mode, String tag) {
    duration_millis_ = duration_millis;
}

int WaitInstruction::Run(Wheel *left_wheel, Wheel *right_wheel) {
    COROUTINE_BEGIN();
    COROUTINE_DELAY(duration_millis_);
    COROUTINE_END();
}

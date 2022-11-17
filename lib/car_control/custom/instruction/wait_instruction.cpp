#include "wait_instruction.h"

WaitInstruction::WaitInstruction(int duration_millis, InstructionMode mode, String tag) : InstructionImpl(mode, tag) {
    duration_millis_ = duration_millis;
}

int WaitInstruction::runCoroutine() {
    COROUTINE_BEGIN();
    COROUTINE_DELAY(duration_millis_);
    COROUTINE_END();
}

#include "WaitInstruction.h"

int WaitInstruction::runCoroutine() {
    COROUTINE_BEGIN();
    COROUTINE_DELAY(duration_millis_);
    COROUTINE_END();
}

WaitInstruction::WaitInstruction(int duration_millis) {
    duration_millis_ = duration_millis;
}

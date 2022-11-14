#include "wait_instruction.h"

int wait_instruction::runCoroutine() {
    COROUTINE_BEGIN();
    COROUTINE_DELAY(duration_millis_);
    COROUTINE_END();
}

wait_instruction::wait_instruction(int duration_millis) {
    duration_millis_ = duration_millis;
}

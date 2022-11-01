#include "CoroutineInstruction.h"

int CoroutineInstruction::runCoroutine() {
    // do something...
    return 0;
}

void CoroutineInstruction::Run(Wheel *left_wheel, Wheel *right_wheel) {
    if (left_wheel_ == nullptr) left_wheel_ = left_wheel;
    if (right_wheel_ == nullptr) right_wheel_ = right_wheel;
    runCoroutine();
}

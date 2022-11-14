#include "force_stop_instruction.h"

ForceStopInstruction::ForceStopInstruction() = default;

int ForceStopInstruction::runCoroutine() {
    COROUTINE_BEGIN();
    left_wheel_->UpdateSpeed(0);
    right_wheel_->UpdateSpeed(0);
    left_wheel_->Apply();
    right_wheel_->Apply();
    COROUTINE_END();
}

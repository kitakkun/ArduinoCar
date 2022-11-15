#include "force_stop_instruction.h"

ForceStopInstruction::ForceStopInstruction(InstructionMode mode, String tag) : InstructionImpl(mode, tag) {}

int ForceStopInstruction::runCoroutine() {
    COROUTINE_BEGIN();
    left_wheel_->UpdateSpeed(0);
    right_wheel_->UpdateSpeed(0);
    COROUTINE_END();
}

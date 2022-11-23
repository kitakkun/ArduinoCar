#include "force_stop_instruction.h"

ForceStopInstruction::ForceStopInstruction(InstructionMode mode, String tag) {}

int ForceStopInstruction::Run(Wheel *left_wheel, Wheel *right_wheel) {
    COROUTINE_BEGIN();
    left_wheel->UpdateSpeed(0);
    right_wheel->UpdateSpeed(0);
    COROUTINE_END();
}

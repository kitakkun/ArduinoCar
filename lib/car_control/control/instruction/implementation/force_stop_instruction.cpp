#include "force_stop_instruction.h"

void ForceStopInstruction::Run(Wheel *left_wheel, Wheel *right_wheel) {
    left_wheel->UpdateSpeed(0);
    right_wheel->UpdateSpeed(0);
}

ForceStopInstruction::ForceStopInstruction() = default;

#include "dummy_brain.h"
#include "control/instruction/implementation/log_instruction.h"
#include "control/instruction/implementation/turn_instruction.h"

Instruction *DummyBrain::CalculateNextInstruction(CarState state) {
    return new TurnInstruction(100, 2000);
}

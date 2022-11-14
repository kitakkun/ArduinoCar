#include "dummy_brain.h"
#include "custom/instruction/log_instruction.h"
#include "custom/instruction/turn_instruction.h"

Instruction *DummyBrain::CalculateNextInstruction(CarState state) {
    return new TurnInstruction(100, 2000);
}

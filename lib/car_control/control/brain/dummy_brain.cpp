#include "dummy_brain.h"
#include "control/instruction/implementation/log_instruction.h"

Instruction *DummyBrain::CalculateNextInstruction(CarState state) {
    return new LogInstruction();
}

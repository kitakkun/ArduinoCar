#ifndef EMPTY_INSTRUCTION
#define EMPTY_INSTRUCTION

#include "control/instruction/instruction.h"

class EmptyInstruction : public Instruction {
public:
    void Run(Wheel *left_wheel, Wheel *right_wheel) override;

    bool InterruptionEnabled() override { return false; };
};

#endif //EMPTY_INSTRUCTION

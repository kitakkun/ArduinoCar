#ifndef FORCE_STOP_INSTRUCTION
#define FORCE_STOP_INSTRUCTION


#include "core/logic/instruction.h"

class ForceStopInstruction : public Instruction {
public:
    explicit ForceStopInstruction(InstructionMode mode = none);

    int Run(Wheel *left_wheel, Wheel *right_wheel) override;
};

#endif //FORCE_STOP_INSTRUCTION
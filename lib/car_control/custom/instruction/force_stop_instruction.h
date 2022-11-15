#ifndef FORCE_STOP_INSTRUCTION
#define FORCE_STOP_INSTRUCTION

#include "core/logic/instruction.h"

class ForceStopInstruction : public Instruction {
public:
    explicit ForceStopInstruction(InstructionMode mode = none, String tag = "ForceStopInstruction");

    int runCoroutine() override;
};

#endif //FORCESTOPINSTRUCTION_H
#ifndef FORCE_STOP_INSTRUCTION
#define FORCE_STOP_INSTRUCTION

#include "core/logic/instruction_impl.h"

class ForceStopInstruction : public InstructionImpl {
public:
    explicit ForceStopInstruction(InstructionMode mode = none, String tag = "ForceStopInstruction");

    int runCoroutine() override;
};

#endif //FORCESTOPINSTRUCTION_H
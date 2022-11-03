#ifndef FORCE_STOP_INSTRUCTION
#define FORCE_STOP_INSTRUCTION

#include "control/instruction/instruction.h"

class ForceStopInstruction : public Instruction {
public:
    explicit ForceStopInstruction();
    int runCoroutine() override;
};

#endif //FORCESTOPINSTRUCTION_H
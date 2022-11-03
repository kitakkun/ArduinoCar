#ifndef FORCE_STOP_INSTRUCTION
#define FORCE_STOP_INSTRUCTION

#include "control/instruction/instruction.h"

class ForceStopInstruction : public Instruction {
public:
    explicit ForceStopInstruction();
    void Run(Wheel *left_wheel, Wheel *right_wheel) override;
};

#endif //FORCESTOPINSTRUCTION_H
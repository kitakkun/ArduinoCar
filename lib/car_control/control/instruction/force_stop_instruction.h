#ifndef FORCE_STOP_INSTRUCTION
#define FORCE_STOP_INSTRUCTION

#include "instruction.h"

class ForceStopInstruction : public Instruction {
public:
    explicit ForceStopInstruction(int speed);
    void Run(Wheel *left_wheel, Wheel *right_wheel) override;
private:
    int speed_;
};

#endif //FORCESTOPINSTRUCTION_H
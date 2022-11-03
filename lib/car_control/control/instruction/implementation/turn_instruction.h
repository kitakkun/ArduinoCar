#ifndef TURN_INSTRUCTION_H
#define TURN_INSTRUCTION_H

#include "control/instruction/instruction.h"

/*
 * 180度回転する指令
 */
class TurnInstruction : public Instruction {
public:
    explicit TurnInstruction();
    void Run(Wheel *left_wheel, Wheel *right_wheel) override;
};

#endif //ACCELERATEINSTRUCTION_H

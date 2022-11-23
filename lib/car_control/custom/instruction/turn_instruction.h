#ifndef TURN_INSTRUCTION_H
#define TURN_INSTRUCTION_H

#include "core/logic/instruction.h"

/*
 * 180度回転する指令
 */
class TurnInstruction : public Instruction {
public:
    explicit TurnInstruction(int speed, int duration, InstructionMode mode = none, String tag = "TurnInstruction");

    int Run(Wheel *left_wheel, Wheel *right_wheel) override;

private:
    int speed_;
    int duration_;
};

#endif //ACCELERATEINSTRUCTION_H

#ifndef TURN_INSTRUCTION_H
#define TURN_INSTRUCTION_H

#include "control/instruction/instruction.h"

/*
 * 180度回転する指令
 */
class TurnInstruction : public Instruction {
public:
    explicit TurnInstruction(int speed, int duration);
    int runCoroutine() override;
private:
    int speed_;
    int duration_;
};

#endif //ACCELERATEINSTRUCTION_H
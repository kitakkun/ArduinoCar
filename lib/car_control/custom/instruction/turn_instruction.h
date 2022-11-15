#ifndef TURN_INSTRUCTION_H
#define TURN_INSTRUCTION_H

#include "core/logic/instruction_impl.h"

/*
 * 180度回転する指令
 */
class TurnInstruction : public InstructionImpl {
public:
    explicit TurnInstruction(int speed, int duration, InstructionMode mode = none, String tag = "TurnInstruction");

    int runCoroutine() override;

private:
    int speed_;
    int duration_;
};

#endif //ACCELERATEINSTRUCTION_H

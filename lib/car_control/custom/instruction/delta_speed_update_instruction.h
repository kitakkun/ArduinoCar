#ifndef ACCELERATEINSTRUCTION_H
#define ACCELERATEINSTRUCTION_H

#include "core/instruction.h"

/*
 * スピード差分調整指令
 */
class DeltaSpeedUpdateInstruction : public Instruction {
public:
    explicit DeltaSpeedUpdateInstruction(int amount);
    DeltaSpeedUpdateInstruction(int l_amount, int r_amount);
    int runCoroutine() override;
private:
    int l_amount_;
    int r_amount_;
};

#endif //ACCELERATEINSTRUCTION_H

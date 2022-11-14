#ifndef ACCELERATEINSTRUCTION_H
#define ACCELERATEINSTRUCTION_H

#include "core/instruction.h"

/*
 * 加速指令
 */
class AccelerateInstruction : public Instruction {
public:
    explicit AccelerateInstruction(int amount);
    AccelerateInstruction(int l_amount, int r_amount);
    int runCoroutine() override;
private:
    int l_amount_;
    int r_amount_;
};

#endif //ACCELERATEINSTRUCTION_H

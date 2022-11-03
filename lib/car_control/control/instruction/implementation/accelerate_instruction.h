#ifndef ACCELERATEINSTRUCTION_H
#define ACCELERATEINSTRUCTION_H

#include "control/instruction/instruction.h"

/*
 * 加速指令
 */
class AccelerateInstruction : public Instruction {
public:
    explicit AccelerateInstruction(int amount);
    void Run(Wheel *left_wheel, Wheel *right_wheel) override;
private:
    int amount_;    /// 加速量
};

#endif //ACCELERATEINSTRUCTION_H

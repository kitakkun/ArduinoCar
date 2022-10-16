#ifndef ACCELERATEINSTRUCTION_H
#define ACCELERATEINSTRUCTION_H

#include "instruction.h"

/*
 * 加速命令
 */
class AccelerateInstruction : public Instruction {
public:
    explicit AccelerateInstruction(int amount);
    void Run(Wheel *left_wheel, Wheel *right_wheel) override;
private:
    int amount_;
};

#endif //ACCELERATEINSTRUCTION_H

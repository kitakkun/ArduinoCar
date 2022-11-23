#ifndef ACCELERATEINSTRUCTION_H
#define ACCELERATEINSTRUCTION_H

#include "core/logic/instruction.h"

/*
 * スピード差分調整指令
 */
class DeltaSpeedUpdateInstruction : public Instruction {
public:
    explicit DeltaSpeedUpdateInstruction(int amount, InstructionMode mode = none, String tag = "DeltaSpeedUpdateInstruction");

    DeltaSpeedUpdateInstruction(int l_amount, int r_amount, InstructionMode mode = none, String tag = "DeltaSpeedUpdateInstruction");

    int Run(Wheel *left_wheel, Wheel *right_wheel) override;

    InstructionMode Mode() override;

private:
    int l_amount_;
    int r_amount_;
    InstructionMode mode_;
};

#endif //ACCELERATEINSTRUCTION_H

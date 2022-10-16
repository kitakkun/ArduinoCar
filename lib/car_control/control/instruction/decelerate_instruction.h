#ifndef DECELERATE_INSTRUCTION
#define DECELERATE_INSTRUCTION

#include "instruction.h"

/*
 * 減速指令
 */
class DecelerateInstruction : public Instruction {
public:
    explicit DecelerateInstruction(int amount);
    void Run(Wheel *left_wheel, Wheel *right_wheel) override;
private:
    int amount_;    /// 減速量
};

#endif //DECELERATE_INSTRUCTION

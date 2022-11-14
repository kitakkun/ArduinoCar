#ifndef DECELERATE_INSTRUCTION
#define DECELERATE_INSTRUCTION

#include "core/instruction.h"

/*
 * 減速指令
 */
class DecelerateInstruction : public Instruction {
public:
    explicit DecelerateInstruction(int amount);
    int runCoroutine() override;
private:
    int amount_;    /// 減速量
};

#endif //DECELERATE_INSTRUCTION

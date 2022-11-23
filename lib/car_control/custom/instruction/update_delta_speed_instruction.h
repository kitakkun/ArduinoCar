#ifndef UPDATE_DELTA_SPEED_INSTRUCTION
#define UPDATE_DELTA_SPEED_INSTRUCTION

#include "core/logic/instruction.h"

/*
 * スピード差分調整指令
 */
class UpdateDeltaSpeedInstruction : public Instruction {
public:
    explicit UpdateDeltaSpeedInstruction(int amount, InstructionMode mode = none);

    UpdateDeltaSpeedInstruction(int l_amount, int r_amount, InstructionMode mode = none);

    int Run(Wheel *left_wheel, Wheel *right_wheel) override;

private:
    int l_amount_;
    int r_amount_;
};

#endif // UPDATE_DELTA_SPEED_INSTRUCTION

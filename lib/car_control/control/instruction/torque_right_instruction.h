#ifndef TORQUE_RIGHT_INSTRUCTION_H
#define TORQUE_RIGHT_INSTRUCTION_H

#include "instruction.h"

/**
 * 右へ曲がる指令
 */
class TorqueRightInstruction : public Instruction {
public:
    explicit TorqueRightInstruction(int force);

    void Run(Wheel *left_wheel, Wheel *right_wheel) override;

    bool InterruptionEnabled() override;

private:
    int force_;     /// 加えるトルクの強さ
};

#endif //TORQUE_RIGHT_INSTRUCTION_H

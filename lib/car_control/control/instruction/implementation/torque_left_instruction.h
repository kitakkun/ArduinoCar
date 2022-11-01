#ifndef TORQUE_LEFT_INSTRUCTION_H
#define TORQUE_LEFT_INSTRUCTION_H

#include "control/instruction/instruction.h"

/**
 * 左に曲がる指令
 */
class TorqueLeftInstruction : public Instruction {
public:
    explicit TorqueLeftInstruction(int force);

    void Run(Wheel *left_wheel, Wheel *right_wheel) override;

private:
    int force_;     /// 加えるトルクの強さ
};

#endif //TORQUE_LEFT_INSTRUCTION_H

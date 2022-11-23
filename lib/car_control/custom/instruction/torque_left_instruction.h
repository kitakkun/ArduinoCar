#ifndef TORQUE_LEFT_INSTRUCTION_H
#define TORQUE_LEFT_INSTRUCTION_H


#include "core/logic/instruction.h"

/**
 * 左に曲がる指令
 */
class TorqueLeftInstruction : public Instruction {
public:
    explicit TorqueLeftInstruction(int base_speed, int force, InstructionMode mode = none);

    int Run(Wheel *left_wheel, Wheel *right_wheel) override;

private:
    int base_speed_;
    int force_;     /// 加えるトルクの強さ
};

#endif //TORQUE_LEFT_INSTRUCTION_H

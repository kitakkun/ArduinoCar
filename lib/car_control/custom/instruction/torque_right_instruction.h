#ifndef TORQUE_RIGHT_INSTRUCTION_H
#define TORQUE_RIGHT_INSTRUCTION_H

#include "core/logic/instruction.h"

/**
 * 右折命令
 */
class TorqueRightInstruction : public Instruction {
public:
    explicit TorqueRightInstruction(int base_speed, int force, InstructionMode mode = none);

    int Run(Wheel *left_wheel, Wheel *right_wheel) override;

private:
    int base_speed_;
    int force_;     /// 加えるトルクの強さ
};

#endif //TORQUE_RIGHT_INSTRUCTION_H

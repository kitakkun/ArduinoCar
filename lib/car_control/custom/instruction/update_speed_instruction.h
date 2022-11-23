#ifndef LABORATORY_WORK_IN_INFORMATION_ENGINEERING_III_UPDATE_SPEED_INSTRUCTION_H
#define LABORATORY_WORK_IN_INFORMATION_ENGINEERING_III_UPDATE_SPEED_INSTRUCTION_H

#include "core/logic/instruction.h"

/**
 * 速度更新命令
 */
class UpdateSpeedInstruction : public Instruction {
public:
    UpdateSpeedInstruction(int left_speed, int right_speed, InstructionMode mode = none);

    explicit UpdateSpeedInstruction(int speed, InstructionMode mode = none);

    int Run(Wheel *left_wheel, Wheel *right_wheel) override;

private:
    int left_speed_;
    int right_speed_;
};

#endif //LABORATORY_WORK_IN_INFORMATION_ENGINEERING_III_UPDATE_SPEED_INSTRUCTION_H

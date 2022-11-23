#ifndef LABORATORY_WORK_IN_INFORMATION_ENGINEERING_III_FORCE_SPEED_UPDATE_INSTRUCTION_H
#define LABORATORY_WORK_IN_INFORMATION_ENGINEERING_III_FORCE_SPEED_UPDATE_INSTRUCTION_H

#include "core/logic/instruction.h"

class ForceSpeedUpdateInstruction : public Instruction {
public:
    ForceSpeedUpdateInstruction(int left_speed, int right_speed, InstructionMode mode = none, String tag = "ForceSpeedUpdateInstruction");

    explicit ForceSpeedUpdateInstruction(int speed, InstructionMode mode = none, String tag = "ForceSpeedUpdateInstruction");

    int Run(Wheel *left_wheel, Wheel *right_wheel) override;

private:
    int left_speed_;
    int right_speed_;
};

#endif //LABORATORY_WORK_IN_INFORMATION_ENGINEERING_III_FORCE_SPEED_UPDATE_INSTRUCTION_H

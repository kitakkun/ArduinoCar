#ifndef LABORATORY_WORK_IN_INFORMATION_ENGINEERING_III_FORCE_SPEED_UPDATE_INSTRUCTION_H
#define LABORATORY_WORK_IN_INFORMATION_ENGINEERING_III_FORCE_SPEED_UPDATE_INSTRUCTION_H

#include "instruction.h"

class ForceSpeedUpdateInstruction: public Instruction {
public:
    void Run(Wheel *left_wheel, Wheel *right_wheel) override;
    ForceSpeedUpdateInstruction(int left_speed, int right_speed);
private:
    int left_speed_;
    int right_speed_;
};

#endif //LABORATORY_WORK_IN_INFORMATION_ENGINEERING_III_FORCE_SPEED_UPDATE_INSTRUCTION_H

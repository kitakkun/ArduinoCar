#ifndef LABORATORY_WORK_IN_INFORMATION_ENGINEERING_III_FORCE_SPEED_UPDATE_INSTRUCTION_H
#define LABORATORY_WORK_IN_INFORMATION_ENGINEERING_III_FORCE_SPEED_UPDATE_INSTRUCTION_H

#include "core/logic/instruction.h"

class ForceSpeedUpdateInstruction: public Instruction {
public:
    int runCoroutine() override;
    ForceSpeedUpdateInstruction(int left_speed, int right_speed);
    ForceSpeedUpdateInstruction(int speed);
private:
    int left_speed_;
    int right_speed_;
};

#endif //LABORATORY_WORK_IN_INFORMATION_ENGINEERING_III_FORCE_SPEED_UPDATE_INSTRUCTION_H

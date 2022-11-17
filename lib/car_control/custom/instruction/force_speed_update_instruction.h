#ifndef LABORATORY_WORK_IN_INFORMATION_ENGINEERING_III_FORCE_SPEED_UPDATE_INSTRUCTION_H
#define LABORATORY_WORK_IN_INFORMATION_ENGINEERING_III_FORCE_SPEED_UPDATE_INSTRUCTION_H

#include "core/logic/instruction_impl.h"

class ForceSpeedUpdateInstruction: public InstructionImpl {
public:
    int runCoroutine() override;
    ForceSpeedUpdateInstruction(int left_speed, int right_speed, InstructionMode mode = none, String tag="ForceSpeedUpdateInstruction");
    explicit ForceSpeedUpdateInstruction(int speed, InstructionMode mode = none, String tag="ForceSpeedUpdateInstruction");
private:
    int left_speed_;
    int right_speed_;
};

#endif //LABORATORY_WORK_IN_INFORMATION_ENGINEERING_III_FORCE_SPEED_UPDATE_INSTRUCTION_H

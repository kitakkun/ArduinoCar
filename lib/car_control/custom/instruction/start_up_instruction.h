#ifndef LABORATORY_WORK_IN_INFORMATION_ENGINEERING_III_START_UP_INSTRUCTION_H
#define LABORATORY_WORK_IN_INFORMATION_ENGINEERING_III_START_UP_INSTRUCTION_H


#include "core/logic/instruction.h"

class StartUpInstruction : public Instruction {
public:
    StartUpInstruction(int startup_speed, int base_speed, unsigned long duration_millis);
    int Run(Wheel *left_wheel, Wheel *right_wheel) override;
private:
    int startup_speed_;
    int base_speed_;
    unsigned long duration_millis_;
};


#endif //LABORATORY_WORK_IN_INFORMATION_ENGINEERING_III_START_UP_INSTRUCTION_H

#ifndef LABORATORY_WORK_IN_INFORMATION_ENGINEERING_III_WAIT_INSTRUCTION_H
#define LABORATORY_WORK_IN_INFORMATION_ENGINEERING_III_WAIT_INSTRUCTION_H

#include "core/logic/instruction.h"

class WaitInstruction : public Instruction {
public:
    explicit WaitInstruction(int duration_millis, InstructionMode mode = none, String tag = "WaitInstruction");

    int Run(Wheel *left_wheel, Wheel *right_wheel) override;

private:
    int duration_millis_;
};


#endif //LABORATORY_WORK_IN_INFORMATION_ENGINEERING_III_WAIT_INSTRUCTION_H

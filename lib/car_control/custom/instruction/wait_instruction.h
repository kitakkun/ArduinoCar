#ifndef LABORATORY_WORK_IN_INFORMATION_ENGINEERING_III_WAIT_INSTRUCTION_H
#define LABORATORY_WORK_IN_INFORMATION_ENGINEERING_III_WAIT_INSTRUCTION_H

#include "core/logic/instruction_impl.h"

class WaitInstruction : public InstructionImpl {
public:
    explicit WaitInstruction(int duration_millis, InstructionMode mode = none, String tag = "WaitInstruction");

    int runCoroutine() override;

private:
    int duration_millis_;
};


#endif //LABORATORY_WORK_IN_INFORMATION_ENGINEERING_III_WAIT_INSTRUCTION_H

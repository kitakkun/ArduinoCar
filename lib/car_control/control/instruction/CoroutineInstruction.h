#ifndef LABORATORY_WORK_IN_INFORMATION_ENGINEERING_III_COROUTINEINSTRUCTION_H
#define LABORATORY_WORK_IN_INFORMATION_ENGINEERING_III_COROUTINEINSTRUCTION_H

#include <AceRoutine.h>
#include "instruction.h"

class CoroutineInstruction : ace_routine::Coroutine, Instruction {
public:
    int runCoroutine() override;
    void Run(Wheel *left_wheel, Wheel *right_wheel) override;
private:
    Wheel *left_wheel_;
    Wheel *right_wheel_;
    bool is_first_run_ = true;
};

#endif //LABORATORY_WORK_IN_INFORMATION_ENGINEERING_III_COROUTINEINSTRUCTION_H

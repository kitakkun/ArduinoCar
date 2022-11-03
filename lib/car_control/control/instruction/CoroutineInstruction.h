#ifndef LABORATORY_WORK_IN_INFORMATION_ENGINEERING_III_COROUTINEINSTRUCTION_H
#define LABORATORY_WORK_IN_INFORMATION_ENGINEERING_III_COROUTINEINSTRUCTION_H

#include <AceRoutine.h>
#include "instruction.h"

#define COROUTINE_COMPLETE() isCompleted_ = true; COROUTINE_END();

class CoroutineInstruction : public Instruction {
public:
    virtual int runCoroutine() = 0;
    void Run(Wheel *left_wheel, Wheel *right_wheel) override;
protected:
    Wheel *left_wheel_;
    Wheel *right_wheel_;
};

#endif //LABORATORY_WORK_IN_INFORMATION_ENGINEERING_III_COROUTINEINSTRUCTION_H

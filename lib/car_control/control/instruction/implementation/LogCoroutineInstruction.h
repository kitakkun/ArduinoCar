#ifndef LABORATORY_WORK_IN_INFORMATION_ENGINEERING_III_LOGCOROUTINEINSTRUCTION_H
#define LABORATORY_WORK_IN_INFORMATION_ENGINEERING_III_LOGCOROUTINEINSTRUCTION_H

#include "control/instruction/CoroutineInstruction.h"

class LogCoroutineInstruction : public CoroutineInstruction, ace_routine::Coroutine {
public:
    int runCoroutine() override;
private:
    int counter = 0;
};


#endif //LABORATORY_WORK_IN_INFORMATION_ENGINEERING_III_LOGCOROUTINEINSTRUCTION_H

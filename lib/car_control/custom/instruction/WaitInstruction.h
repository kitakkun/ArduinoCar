#ifndef LABORATORY_WORK_IN_INFORMATION_ENGINEERING_III_WAITINSTRUCTION_H
#define LABORATORY_WORK_IN_INFORMATION_ENGINEERING_III_WAITINSTRUCTION_H

#include "core/instruction.h"

class WaitInstruction : public Instruction {
public:
    explicit WaitInstruction(int duration_millis);
    int runCoroutine() override;
private:
    int duration_millis_;
};


#endif //LABORATORY_WORK_IN_INFORMATION_ENGINEERING_III_WAITINSTRUCTION_H

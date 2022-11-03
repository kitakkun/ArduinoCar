#ifndef LABORATORY_WORK_IN_INFORMATION_ENGINEERING_III_LOG_INSTRUCTION_H
#define LABORATORY_WORK_IN_INFORMATION_ENGINEERING_III_LOG_INSTRUCTION_H

#include "control/instruction/instruction.h"

class LogInstruction: public Instruction{
public:
    int runCoroutine() override;
};


#endif //LABORATORY_WORK_IN_INFORMATION_ENGINEERING_III_LOG_INSTRUCTION_H

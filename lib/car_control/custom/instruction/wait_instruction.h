#ifndef LABORATORY_WORK_IN_INFORMATION_ENGINEERING_III_WAIT_INSTRUCTION_H
#define LABORATORY_WORK_IN_INFORMATION_ENGINEERING_III_WAIT_INSTRUCTION_H

#include "core/instruction.h"

class wait_instruction : public Instruction {
public:
    explicit wait_instruction(int duration_millis);
    int runCoroutine() override;
private:
    int duration_millis_;
};


#endif //LABORATORY_WORK_IN_INFORMATION_ENGINEERING_III_WAIT_INSTRUCTION_H

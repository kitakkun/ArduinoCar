#ifndef LABORATORY_WORK_IN_INFORMATION_ENGINEERING_III_UPDATE_DIRECTION_INSTRUCTION_H
#define LABORATORY_WORK_IN_INFORMATION_ENGINEERING_III_UPDATE_DIRECTION_INSTRUCTION_H


#include "core/instruction.h"

class UpdateDirectionInstruction : public Instruction {
public:
    explicit UpdateDirectionInstruction(MoveDirection direction);
    int runCoroutine() override;
private:
    MoveDirection direction_;
};


#endif //LABORATORY_WORK_IN_INFORMATION_ENGINEERING_III_UPDATE_DIRECTION_INSTRUCTION_H

#ifndef LABORATORY_WORK_IN_INFORMATION_ENGINEERING_III_UPDATE_DIRECTION_INSTRUCTION_H
#define LABORATORY_WORK_IN_INFORMATION_ENGINEERING_III_UPDATE_DIRECTION_INSTRUCTION_H


#include "core/logic/instruction_impl.h"

class UpdateDirectionInstruction : public InstructionImpl {
public:
    explicit UpdateDirectionInstruction(MoveDirection direction, InstructionMode mode = none,
                                        String tag = "UpdateDirectionInstruction");

    int runCoroutine() override;

private:
    MoveDirection direction_;
};


#endif //LABORATORY_WORK_IN_INFORMATION_ENGINEERING_III_UPDATE_DIRECTION_INSTRUCTION_H

#ifndef LABORATORY_WORK_IN_INFORMATION_ENGINEERING_III_DUMMY_BRAIN_H
#define LABORATORY_WORK_IN_INFORMATION_ENGINEERING_III_DUMMY_BRAIN_H

#include "core/brain.h"

class DummyBrain : public Brain {
public:
    Instruction * CalculateNextInstruction(CarState state) override;
};

#endif //LABORATORY_WORK_IN_INFORMATION_ENGINEERING_III_DUMMY_BRAIN_H

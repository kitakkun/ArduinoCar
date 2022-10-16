#ifndef BRAIN_H
#define BRAIN_H

#include "car_state.h"
#include "instruction.h"

class Brain {
public:
    // 現在の車の情報を元に次に取るべき行動を決定
    virtual Instruction *CalculateNextInstruction(CarState state) = 0;
};

#endif //BRAIN_H

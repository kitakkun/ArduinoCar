#ifndef INSTRUCTION_H
#define INSTRUCTION_H

#include "wheel.h"

// 車に対する指令
class Instruction {
public:
    virtual void Run(Wheel* left_wheel, Wheel* right_wheel);
    bool InterruptionEnabled();
private:
    bool enable_interruption = false;   // 割り込み処理するかどうかのフラグ
};

#endif //INSTRUCTION_H

#ifndef LABORATORY_WORK_IN_INFORMATION_ENGINEERING_III_INSTRUCTION_H
#define LABORATORY_WORK_IN_INFORMATION_ENGINEERING_III_INSTRUCTION_H

#include "ace_routine/Coroutine.h"
#include "core/component/wheel.h"
#include "instruction_mode.h"

/**
 * 車に対する指令を表す抽象クラス
 * 継承して中身を実装することで様々な制御を作れる
 */
class Instruction : public ace_routine::Coroutine {
public:
    virtual ~Instruction() = default;

    virtual int Run(Wheel *left_wheel, Wheel *right_wheel) = 0;

    int runCoroutine() override { return 0; }

    virtual InstructionMode Mode() { return none; }
};

#endif //LABORATORY_WORK_IN_INFORMATION_ENGINEERING_III_INSTRUCTION_H

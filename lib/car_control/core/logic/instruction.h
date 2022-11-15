#ifndef INSTRUCTION_H
#define INSTRUCTION_H

#include "core/component/wheel.h"
#include "ace_routine/Coroutine.h"
#include "instruction_mode.h"

/**
 * 車に対する指令を表す抽象クラス
 * 継承して中身を実装することで様々な制御を作れる
 */
class Instruction : public ace_routine::Coroutine {
public:
    explicit Instruction(InstructionMode mode = none);

    int runCoroutine() override { return 0; };

    void Setup(Wheel *left_wheel, Wheel *right_wheel);

    InstructionMode Mode();

    void SetMode(InstructionMode mode);

protected:
    Wheel *left_wheel_;
    Wheel *right_wheel_;
    InstructionMode mode_;
};

#endif //INSTRUCTION_H

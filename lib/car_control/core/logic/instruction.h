#ifndef INSTRUCTION_H
#define INSTRUCTION_H

#include "core/component/wheel_impl.h"
#include "ace_routine/Coroutine.h"
#include "instruction_mode.h"
#include "core/debug/debuggable.h"

/**
 * 車に対する指令を表す抽象クラス
 * 継承して中身を実装することで様々な制御を作れる
 */
class Instruction : public ace_routine::Coroutine, public Debuggable {
public:
    virtual ~Instruction();

    explicit Instruction(InstructionMode mode = none, String tag="Instruction");

    int runCoroutine() override { return 0; };

    void Setup(WheelImpl *left_wheel, WheelImpl *right_wheel);

    InstructionMode Mode();

    void SetMode(InstructionMode mode);

protected:
    WheelImpl *left_wheel_;
    WheelImpl *right_wheel_;
    InstructionMode mode_;
};

#endif //INSTRUCTION_H

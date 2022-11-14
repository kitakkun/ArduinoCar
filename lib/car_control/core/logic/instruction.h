#ifndef INSTRUCTION_H
#define INSTRUCTION_H

#include "core/component/wheel.h"
#include "ace_routine/Coroutine.h"

/**
 * 車に対する指令を表す抽象クラス
 * 継承して中身を実装することで様々な制御を作れる
 */
class Instruction : public ace_routine::Coroutine {
public:
    /**
     * デストラクタ
     */
    virtual ~Instruction() = default;

    int runCoroutine() override { return 0; };

    void Setup(Wheel *left_wheel, Wheel *right_wheel);
protected:
    Wheel *left_wheel_;
    Wheel *right_wheel_;
};

#endif //INSTRUCTION_H

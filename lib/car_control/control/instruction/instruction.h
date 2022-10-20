#ifndef INSTRUCTION_H
#define INSTRUCTION_H

#include "../../component/wheel/wheel.h"

/**
 * 車に対する指令を表す抽象クラス
 * 継承して中身を実装することで様々な制御を作れる
 */
class Instruction {
public:
    /**
     * デストラクタ
     */
    virtual ~Instruction() = default;

    /**
     * 車の車輪を制御する。
     * @param left_wheel 左車輪のインスタンス
     * @param right_wheel 右車輪のインスタンス
     */
    virtual void Run(Wheel* left_wheel, Wheel* right_wheel) = 0;

    /**
     * 割り込みをするか否かを取得。
     * @return 割り込みが有効かどうか
     */
    bool InterruptionEnabled() { return false; };
};

#endif //INSTRUCTION_H

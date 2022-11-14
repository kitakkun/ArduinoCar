#ifndef BRAIN_H
#define BRAIN_H

#include "car_state.h"
#include "core/instruction.h"

/**
 * 車の頭脳に相当するクラス
 * 様々な状況に応じた制御はこのクラスが行う
 */
class Brain {
public:
    /**
     * デストラクタ
     */
    virtual ~Brain() = default;

    /**
     * 現在の車の情報を元に指令を返す
     */
    virtual Instruction *CalculateNextInstruction(CarState state) = 0;
};

#endif //BRAIN_H

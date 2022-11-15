#ifndef BRAIN_H
#define BRAIN_H

#include "instruction.h"

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
     * 次の行動を決定
     */
    virtual Instruction *CalculateNextInstruction() = 0;
};

#endif //BRAIN_H

#ifndef CAR_H
#define CAR_H

#include "core/wheel.h"
#include "core/brain.h"
#include "core/instruction.h"

class Car {
public:
    explicit Car(Brain *brain, Wheel *left_wheel, Wheel *right_wheel);

    virtual ~Car() = 0;

    /**
     * センサー情報を更新します。
     */
    virtual void UpdateSensors() = 0;

    /**
     * 次に取るべき行動を決定する。
     * Instructionの設定を行う。
     */
    virtual void Think() = 0;

    /**
     * 設定されている指令を実行に移す。
     */
    virtual void Act() = 0;

protected:
    Brain *brain_;          /// 車の状態を見て指令を送るアルゴリズム実装部
    Wheel *left_wheel_;     /// 左の車輪
    Wheel *right_wheel_;    /// 右の車輪
};

#endif

#ifndef CAR_H
#define CAR_H

#include "core/component/wheel_impl.h"
#include "core/logic/brain.h"
#include "core/logic/instruction.h"
#include "car_builder.h"

class CarBuilder;

class Car {
public:
    Car(CarBuilder *builder);

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
    WheelImpl *left_wheel_;     /// 左の車輪
    WheelImpl *right_wheel_;    /// 右の車輪
};

#endif

#ifndef LABORATORY_WORK_IN_INFORMATION_ENGINEERING_III_WHEEL_H
#define LABORATORY_WORK_IN_INFORMATION_ENGINEERING_III_WHEEL_H

#include "core/data_model/move_direction.h"

class Wheel {
public:
    /**
     * 速度の更新
     * @param speed 速度
     */
    virtual void UpdateSpeed(int speed) = 0;

    /**
     * 速度の更新（差分）
     * @param delta_speed 速度差分
     */
    virtual void UpdateDeltaSpeed(int delta_speed) = 0;

    /**
     * 回転方向の転換
     * @param direction 進行方向
     */
    virtual void UpdateDirection(MoveDirection direction) = 0;

    /**
     * 現在の回転方向を取得
     * @return 進行方向
     */
    virtual MoveDirection Direction() = 0;

    /**
     * 現在のスピードを取得
     * @return 現在のスピード
     */
    virtual int Speed() = 0;
};

#endif //LABORATORY_WORK_IN_INFORMATION_ENGINEERING_III_WHEEL_H

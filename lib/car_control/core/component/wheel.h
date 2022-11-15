#ifndef WHEEL_H
#define WHEEL_H

#include "core/data_model/move_direction.h"
#include "core/debug/debuggable.h"

/**
 * 車輪の速度制御や回転方向制御を行うクラス
 */
class Wheel : public Debuggable {
public:
    /**
     * コンストラクタ
     * @param plus_pin プラスのピン
     * @param minus_pin マイナスのピン
     * @param pwm_pin 速度調整用PWMのピン
     */
    Wheel(int plus_pin, int minus_pin, int pwm_pin, String tag = "Wheel");

    /**
     * 速度の更新
     * @param speed 速度
     */
    void UpdateSpeed(int speed);

    /**
     * 速度の更新（差分）
     * @param delta_speed 速度差分
     */
    void UpdateDeltaSpeed(int delta_speed);

    /**
     * 回転方向の転換
     * @param direction 進行方向
     */
    void UpdateDirection(MoveDirection direction);

    /**
     * 現在の回転方向を取得
     * @return 進行方向
     */
    MoveDirection Direction();

    /**
     * 現在のスピードを取得
     * @return 現在のスピード
     */
    int Speed() const;

private:
    int plus_pin_;      /// プラスピン
    int minus_pin_;     /// マイナスピン
    int pwm_pin_;       /// PWMのピン
    MoveDirection direction_;     /// 進行方向
    int speed_;     /// 速度

    void ApplySpeed();

    void ApplyDirection();
};

#endif

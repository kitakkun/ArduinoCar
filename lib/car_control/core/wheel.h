#ifndef WHEEL_H
#define WHEEL_H

#include "move_direction.h"

/**
 * 車輪の速度制御や回転方向制御を行うクラス
 */
class Wheel {
public:
    /**
     * コンストラクタ
     * @param plus_pin プラスのピン
     * @param minus_pin マイナスのピン
     * @param pwm_pin 速度調整用PWMのピン
     */
    Wheel(int plus_pin, int minus_pin, int pwm_pin);

    /**
     * 加速する
     * @param amount 加速する量
     */
    void Accelerate(signed int amount);

    /**
     * 減速する
     * @param amount 減速する量
     */
    void Decelerate(signed int amount);

    /**
     * 速度の更新
     * @param speed 速度
     */
    void UpdateSpeed(signed int speed);

    /**
     * 回転方向の転換
     * @param direction 進行方向
     */
    void UpdateDirection(MoveDirection direction);

    /**
     * 変更内容の反映
     * @deprecated UpdateDirection, UpdateSpeedで即座に更新してしまいますので、不要です。
     */
    void Apply();

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
    MoveDirection direction_ = forward;     /// 進行方向
    int speed_;     /// 速度

    void ApplySpeed() const;
    void ApplyDirection();
};

#endif

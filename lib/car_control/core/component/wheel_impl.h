#ifndef WHEEL_H
#define WHEEL_H

#include "core/data_model/move_direction.h"
#include "core/debug/debuggable.h"
#include "wheel.h"

#define WHEEL_MAX_SPEED 255
#define WHEEL_MIN_SPEED 0

/**
 * 車輪の速度制御や回転方向制御を行うクラス
 */
class WheelImpl : public Wheel {
public:
    /**
     * コンストラクタ
     * @param plus_pin プラスのピン
     * @param minus_pin マイナスのピン
     * @param pwm_pin 速度調整用PWMのピン
     */
    WheelImpl(int plus_pin, int minus_pin, int pwm_pin);

    void UpdateSpeed(int speed) override;

    void UpdateDeltaSpeed(int delta_speed) override;

    void UpdateDirection(MoveDirection direction) override;

    MoveDirection Direction() override;

    int Speed() override;

private:
    int plus_pin_;      /// プラスピン
    int minus_pin_;     /// マイナスピン
    int pwm_pin_;       /// PWMのピン
    int speed_;     /// 速度
    MoveDirection direction_;     /// 進行方向

    void ApplySpeed();

    void ApplyDirection();
};

#endif

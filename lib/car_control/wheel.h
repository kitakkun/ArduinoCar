#ifndef WHEEL_H
#define WHEEL_H

#include "move_direction.h"

/**
 * タイヤクラス
 */
class Wheel {
public:
    Wheel(int plus_pin, int minus_pin, int pwm_pin);
    void Accelerate(signed int amount);
    void Decelerate(signed int amount);
    void UpdateSpeed(signed int speed);
    void UpdateSpeed(signed int speed, int milliseconds);
    void UpdateDirection(MoveDirection direction);
    void Apply();
    MoveDirection Direction();
    int Speed();
private:
    int plus_pin_;
    int minus_pin_;
    int pwm_pin_;
    MoveDirection direction_ = forward;
    int speed_;
    void UpdateMoveDirectionBySpeed(int speed);
};

#endif

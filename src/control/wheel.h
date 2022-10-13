#ifndef WHEEL_H
#define WHEEL_H

#include "move_direction.h"

/**
 * タイヤクラス
 */
class Wheel {
    public:
        Wheel(int plus_pin, int minus_pin, int pwm_pin);
        void UpdateSpeed(int speed, int milliseconds);
        MoveDirection Direction();
        int Speed();
    private:
        int plus_pin_;
        int minus_pin_;
        int pwm_pin_;
        MoveDirection direction_ = forward;
        int speed_;
};

#endif

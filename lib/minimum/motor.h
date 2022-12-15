#ifndef LABORATORY_WORK_IN_INFORMATION_ENGINEERING_III_MOTOR_H
#define LABORATORY_WORK_IN_INFORMATION_ENGINEERING_III_MOTOR_H


#include "move_direction.h"

class Motor {
public:
    Motor(int plus_pin, int minus_pin, int pwm_pin, int gain=0);

    void UpdateSpeed(int speed);

    void UpdateDirection(MoveDirection direction);

    int GetSpeed();

    MoveDirection GetMoveDirection();

private:
    int plus_pin_;
    int minus_pin_;
    int pwm_pin_;
    int speed_;
    int gain_;
    MoveDirection direction_;

    void ApplySpeed();

    void ApplyDirection();
};


#endif //LABORATORY_WORK_IN_INFORMATION_ENGINEERING_III_MOTOR_H

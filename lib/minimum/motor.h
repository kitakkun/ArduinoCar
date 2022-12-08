#ifndef LABORATORY_WORK_IN_INFORMATION_ENGINEERING_III_MOTOR_H
#define LABORATORY_WORK_IN_INFORMATION_ENGINEERING_III_MOTOR_H


#include "move_direction.h"

class Motor {
public:
    Motor(int plus_pin, int minus_pin, int pwm_pin);

    void UpdateSpeed(int speed);

    void UpdateDirection(MoveDirection direction);

    int GetSpeed();

    MoveDirection GetMoveDirection();

private:
    int speed_;
    MoveDirection direction_;

    void ApplySpeed();

    void ApplyDirection();
};


#endif //LABORATORY_WORK_IN_INFORMATION_ENGINEERING_III_MOTOR_H

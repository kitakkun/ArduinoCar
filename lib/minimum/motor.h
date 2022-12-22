#ifndef LABORATORY_WORK_IN_INFORMATION_ENGINEERING_III_MOTOR_H
#define LABORATORY_WORK_IN_INFORMATION_ENGINEERING_III_MOTOR_H


#include "move_direction.h"

class Motor {
public:
    virtual void UpdateSpeed(int speed) = 0;

    virtual void UpdateDirection(MoveDirection direction) = 0;

    virtual int GetSpeed() = 0;

    virtual MoveDirection GetMoveDirection() = 0;
};


#endif //LABORATORY_WORK_IN_INFORMATION_ENGINEERING_III_MOTOR_H

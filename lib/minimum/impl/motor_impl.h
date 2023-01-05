#ifndef LABORATORY_WORK_IN_INFORMATION_ENGINEERING_III_MOTOR_IMPL_H
#define LABORATORY_WORK_IN_INFORMATION_ENGINEERING_III_MOTOR_IMPL_H

#include "interface/motor.h"
#include "ace_routine/Coroutine.h"

class MotorImpl : public Motor, ace_routine::Coroutine {
public:
    MotorImpl(int plus_pin, int minus_pin, int pwm_pin, int gain = 0);

    void UpdateSpeed(int speed) override;

    void UpdateDirection(MoveDirection direction) override;

    int GetSpeed() override;

    int runCoroutine() override;

    MoveDirection GetMoveDirection() override;

private:
    int plus_pin_;
    int minus_pin_;
    int pwm_pin_;
    int speed_;
    int gain_;
    MoveDirection direction_;

    void Apply();
};

#endif //LABORATORY_WORK_IN_INFORMATION_ENGINEERING_III_MOTOR_IMPL_H

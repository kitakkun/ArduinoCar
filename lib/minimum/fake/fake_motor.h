#ifndef LABORATORY_WORK_IN_INFORMATION_ENGINEERING_III_FAKE_MOTOR_H
#define LABORATORY_WORK_IN_INFORMATION_ENGINEERING_III_FAKE_MOTOR_H


#include "motor.h"

class FakeMotor : public Motor {
public:
    explicit FakeMotor();

    void UpdateSpeed(int speed) override;

    void UpdateDirection(MoveDirection direction) override;

    int GetSpeed() override;

    MoveDirection GetMoveDirection() override;

private:
    int speed_;
    MoveDirection direction_;
};


#endif //LABORATORY_WORK_IN_INFORMATION_ENGINEERING_III_FAKE_MOTOR_H

#ifndef LABORATORY_WORK_IN_INFORMATION_ENGINEERING_III_FAKE_WHEEL_H
#define LABORATORY_WORK_IN_INFORMATION_ENGINEERING_III_FAKE_WHEEL_H


#include "core/component/wheel.h"

class FakeWheel : public Wheel {
public:
    explicit FakeWheel();

    void UpdateSpeed(int speed) override;

    void UpdateDeltaSpeed(int delta_speed) override;

    void UpdateDirection(MoveDirection direction) override;

    MoveDirection Direction() override;

    int Speed() override;

private:
    int speed_;
    MoveDirection direction_;
};


#endif //LABORATORY_WORK_IN_INFORMATION_ENGINEERING_III_FAKE_WHEEL_H

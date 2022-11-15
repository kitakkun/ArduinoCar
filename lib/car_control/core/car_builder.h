#ifndef LABORATORY_WORK_IN_INFORMATION_ENGINEERING_III_CAR_BUILDER_H
#define LABORATORY_WORK_IN_INFORMATION_ENGINEERING_III_CAR_BUILDER_H

#include "core/logic/brain.h"
#include "car.h"

class Car;

class CarBuilder {
public:

    void SetLeftWheel(WheelImpl *left_wheel);

    void SetRightWheel(WheelImpl *right_wheel);

    WheelImpl *GetLeftWheel();

    WheelImpl *GetRightWheel();

    virtual Car *Build() = 0;

protected:
    WheelImpl *left_wheel_;
    WheelImpl *right_wheel_;
};


#endif //LABORATORY_WORK_IN_INFORMATION_ENGINEERING_III_CAR_BUILDER_H

#ifndef LABORATORY_WORK_IN_INFORMATION_ENGINEERING_III_CAR_BUILDER_H
#define LABORATORY_WORK_IN_INFORMATION_ENGINEERING_III_CAR_BUILDER_H

#include "car.h"

class Car;

class CarBuilder {
public:
    virtual void SetLeftWheel(Wheel *left_wheel) = 0;

    virtual void SetRightWheel(Wheel *right_wheel) = 0;

    virtual Wheel *GetLeftWheel() = 0;

    virtual Wheel *GetRightWheel() = 0;

    virtual Car *Build() = 0;
};


#endif //LABORATORY_WORK_IN_INFORMATION_ENGINEERING_III_CAR_BUILDER_H

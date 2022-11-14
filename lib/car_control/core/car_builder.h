#ifndef LABORATORY_WORK_IN_INFORMATION_ENGINEERING_III_CAR_BUILDER_H
#define LABORATORY_WORK_IN_INFORMATION_ENGINEERING_III_CAR_BUILDER_H

#include "core/logic/brain.h"
#include "car.h"

class Car;

class CarBuilder {
public:

    void SetLeftWheel(Wheel *left_wheel);

    void SetRightWheel(Wheel *right_wheel);

    Wheel *GetLeftWheel();

    Wheel *GetRightWheel();

    virtual Car *Build() = 0;

protected:
    Wheel *left_wheel_;
    Wheel *right_wheel_;
};


#endif //LABORATORY_WORK_IN_INFORMATION_ENGINEERING_III_CAR_BUILDER_H

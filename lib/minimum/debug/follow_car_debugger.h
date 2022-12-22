#ifndef LABORATORY_WORK_IN_INFORMATION_ENGINEERING_III_FOLLOW_CAR_DEBUGGER_H
#define LABORATORY_WORK_IN_INFORMATION_ENGINEERING_III_FOLLOW_CAR_DEBUGGER_H

#include "car/follow_car.h"

class FollowCarDebugger{
public:
    explicit FollowCarDebugger(FollowCar *follow_car);
    void DebugSensors();
    void DebugMotors();

private:
    FollowCar *follow_car_;
};

#endif //LABORATORY_WORK_IN_INFORMATION_ENGINEERING_III_FOLLOW_CAR_DEBUGGER_H

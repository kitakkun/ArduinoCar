#ifndef LABORATORY_WORK_IN_INFORMATION_ENGINEERING_III_FOLLOW_CAR_DEBUG_H
#define LABORATORY_WORK_IN_INFORMATION_ENGINEERING_III_FOLLOW_CAR_DEBUG_H

#include "car/follow_car.h"

class FollowCarDebugger{
public:
    explicit FollowcarDebugger(FollowCar *follow_car);
    void DebugSensors();
    void DebugMotors();

private:
    FollowCar *follow_car_;
};

#endif //LABORATORY_WORK_IN_INFORMATION_ENGINEERING_III_FOLLOW_CAR_DEBUG_H

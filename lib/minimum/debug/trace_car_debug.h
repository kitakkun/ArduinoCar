#ifndef LABORATORY_WORK_IN_INFORMATION_ENGINEERING_III_TRACE_CAR_DEBUG_H
#define LABORATORY_WORK_IN_INFORMATION_ENGINEERING_III_TRACE_CAR_DEBUG_H

#include "car/trace_car.h"

class TraceCarDebugger{
public:
    explicit FollowcarDebugger(TraceCar *trace_car);
    void DebugSensors();
    void DebugMotors();

private:
    TraceCar *trace_car_;
};

#endif //LABORATORY_WORK_IN_INFORMATION_ENGINEERING_III_TRACE_CAR_DEBUG_H

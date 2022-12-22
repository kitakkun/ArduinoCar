#ifndef LABORATORY_WORK_IN_INFORMATION_ENGINEERING_III_TRACE_CAR_DEBUGGER_H
#define LABORATORY_WORK_IN_INFORMATION_ENGINEERING_III_TRACE_CAR_DEBUGGER_H

#include "car/trace_car.h"

class TraceCarDebugger{
public:
    explicit TraceCarDebugger(TraceCar *trace_car);
    void DebugSensors();
    void DebugMotors();

private:
    TraceCar *trace_car_;
};

#endif //LABORATORY_WORK_IN_INFORMATION_ENGINEERING_III_TRACE_CAR_DEBUGGER_H

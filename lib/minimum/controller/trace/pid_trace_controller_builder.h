#ifndef LABORATORY_WORK_IN_INFORMATION_ENGINEERING_III_PID_TRACE_CONTROLLER_BUILDER_H
#define LABORATORY_WORK_IN_INFORMATION_ENGINEERING_III_PID_TRACE_CONTROLLER_BUILDER_H

#include "car/trace/trace_car.h"
#include "controller/trace/pid_trace_controller.h"

class PidTraceControllerBuilder {
public:
    PidTraceControllerBuilder& SetCar(TraceCar *car);

    PidTraceControllerBuilder& SetBaseSpeed(int base_speed);

    PidTraceControllerBuilder& SetLRSensorDiff(int lr_sensor_diff);

    PidTraceControllerBuilder& SetMaxManipulation(int max_manipulation);

    PidTraceControllerBuilder& SetPWeight(float p_weight);

    PidTraceControllerBuilder& SetDWeight(float d_weight);

    PidTraceController *Build();
private:
    TraceCar *car_;
    int base_speed_;
    int lr_sensor_diff_;
    int max_manipulation_;
    float p_weight_;
    float d_weight_;
};


#endif //LABORATORY_WORK_IN_INFORMATION_ENGINEERING_III_PID_TRACE_CONTROLLER_BUILDER_H

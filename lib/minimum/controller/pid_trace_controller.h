#ifndef LABORATORY_WORK_IN_INFORMATION_ENGINEERING_III_PID_TRACE_CONTROLLER_H
#define LABORATORY_WORK_IN_INFORMATION_ENGINEERING_III_PID_TRACE_CONTROLLER_H


#include "car_controller.h"
#include "trace_car.h"

class PidTraceController : public CarController {
public:
    explicit PidTraceController(
            TraceCar *car,
            int base_speed,
            int lr_sensor_diff,
            int max_manipulation,
            float p_weight,
            float d_weight
    );

    void Update() override;

    void Operate() override;

protected:
    TraceCar *car_;
    int base_speed_;
    int lr_sensor_diff_; // 左右のセンサの個体差
    int max_manipulation_;
    float p_weight_;
    float d_weight_;
    unsigned long last_time_called_;

    virtual void Trace();

private:
    float prev_deviation_;
};


#endif //LABORATORY_WORK_IN_INFORMATION_ENGINEERING_III_PID_TRACE_CONTROLLER_H

#include "pid_trace_controller_builder.h"

PidTraceControllerBuilder &PidTraceControllerBuilder::SetCar(TraceCar *car) {
    this->car_ = car;
    return *this;
}

PidTraceControllerBuilder &PidTraceControllerBuilder::SetBaseSpeed(int base_speed) {
    this->base_speed_ = base_speed;
    return *this;
}

PidTraceControllerBuilder &PidTraceControllerBuilder::SetLRSensorDiff(int lr_sensor_diff) {
    this->lr_sensor_diff_ = lr_sensor_diff;
    return *this;
}

PidTraceControllerBuilder &PidTraceControllerBuilder::SetMaxManipulation(int max_manipulation) {
    this->max_manipulation_ = max_manipulation;
    return *this;
}

PidTraceControllerBuilder &PidTraceControllerBuilder::SetPWeight(float p_weight) {
    this->p_weight_ = p_weight;
    return *this;
}

PidTraceControllerBuilder &PidTraceControllerBuilder::SetDWeight(float d_weight) {
    this->d_weight_ = d_weight;
    return *this;
}

PidTraceController *PidTraceControllerBuilder::Build() {
    return new PidTraceController(
        this->car_,
        this->base_speed_,
        this->lr_sensor_diff_,
        this->max_manipulation_,
        this->p_weight_,
        this->d_weight_
    );
}

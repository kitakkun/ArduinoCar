#ifndef LABORATORY_WORK_IN_INFORMATION_ENGINEERING_III_TRACE_CAR_BUILDER_H
#define LABORATORY_WORK_IN_INFORMATION_ENGINEERING_III_TRACE_CAR_BUILDER_H


#include "interface/sensor/photo_reflector.h"
#include "interface/motor.h"
#include "car/trace/trace_car.h"

class TraceCarBuilder {
public:
    explicit TraceCarBuilder();

    TraceCarBuilder &SetLeftMotor(Motor *left_motor);

    TraceCarBuilder &SetRightMotor(Motor *right_motor);

    TraceCarBuilder &SetLeftReflector(PhotoReflector *left_reflector);

    TraceCarBuilder &SetMidReflector(PhotoReflector *mid_reflector);    

    TraceCarBuilder &SetRightReflector(PhotoReflector *right_reflector);

    TraceCar *Build();

private:
    Motor *left_motor_;
    Motor *right_motor_;
    PhotoReflector *left_reflector_;
    PhotoReflector *mid_reflector_;
    PhotoReflector *right_reflector_;
};


#endif //LABORATORY_WORK_IN_INFORMATION_ENGINEERING_III_TRACE_CAR_BUILDER_H
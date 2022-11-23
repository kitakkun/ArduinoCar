#ifndef LABORATORY_WORK_IN_INFORMATION_ENGINEERING_III_LINE_TRACE_CAR_H
#define LABORATORY_WORK_IN_INFORMATION_ENGINEERING_III_LINE_TRACE_CAR_H


#include "core/car.h"
#include "core/component/photo_reflector_impl.h"
#include "line_trace_car_builder.h"
#include "custom/data_model/line_trace_car_state.h"
#include "custom/brain/line_trace_brain.h"

class LineTraceCarBuilder;

class LineTraceCar : public Car, public Debuggable {
public:
    explicit LineTraceCar(LineTraceCarBuilder *builder, String tag = "LineTraceCar");

    void UpdateSensors() override;

    void Think() override;

    void Act() override;

private:
    LineTraceBrain *brain_;
    Wheel *left_wheel_;
    Wheel *right_wheel_;
    PhotoReflector *mid_reflector_;
    PhotoReflector *left_reflector_;
    PhotoReflector *right_reflector_;
    Instruction *instruction_;

    LineTraceCarState CollectCarState();
};


#endif //LABORATORY_WORK_IN_INFORMATION_ENGINEERING_III_LINE_TRACE_CAR_H

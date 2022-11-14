#ifndef LABORATORY_WORK_IN_INFORMATION_ENGINEERING_III_LINE_TRACE_CAR_H
#define LABORATORY_WORK_IN_INFORMATION_ENGINEERING_III_LINE_TRACE_CAR_H


#include "core/car.h"
#include "core/component/photo_reflector.h"
#include "line_trace_car_builder.h"
#include "custom/data_model/line_trace_car_state.h"
#include "custom/brain/line_trace_brain.h"

class LineTraceCarBuilder;

class LineTraceCar : public Car {
public:
    explicit LineTraceCar(LineTraceCarBuilder *builder);

    void UpdateSensors() override;
    void Think() override;
    void Act() override;
private:
    LineTraceBrain *brain_;
    PhotoReflector *front_mid_reflector_;
    PhotoReflector *front_left_reflector_;
    PhotoReflector *front_right_reflector_;
    PhotoReflector *back_mid_reflector_;
    PhotoReflector *back_left_reflector_;
    PhotoReflector *back_right_reflector_;
    Instruction* instruction_;

    LineTraceCarState CollectCarState();
};


#endif //LABORATORY_WORK_IN_INFORMATION_ENGINEERING_III_LINE_TRACE_CAR_H

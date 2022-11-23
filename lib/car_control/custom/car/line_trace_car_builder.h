#ifndef CAR_BUILDER_H
#define CAR_BUILDER_H

#include "core/component/wheel_impl.h"
#include "core/component/photo_reflector_impl.h"
#include "core/logic/brain.h"
#include "line_trace_car.h"
#include "custom/brain/line_trace_brain.h"

class LineTraceCarBuilder : public CarBuilder {
public:
    LineTraceCarBuilder& SetLeftWheel(Wheel *wheel) override;

    LineTraceCarBuilder& SetRightWheel(Wheel *wheel) override;

    LineTraceCarBuilder& SetBrain(LineTraceBrain *brain);

    LineTraceCarBuilder& SetLeftReflector(PhotoReflector *reflector);

    LineTraceCarBuilder& SetRightReflector(PhotoReflector *reflector);

    LineTraceCarBuilder& SetMidReflector(PhotoReflector *reflector);

    LineTraceBrain *GetBrain();

    Wheel *GetLeftWheel() override;

    Wheel *GetRightWheel() override;

    PhotoReflector *GetLeftReflector();

    PhotoReflector *GetRightReflector();

    PhotoReflector *GetMidReflector();

    Car *Build() override;

private:
    LineTraceBrain *brain_;
    Wheel *left_wheel_;
    Wheel *right_wheel_;
    PhotoReflector *left_reflector_;
    PhotoReflector *right_reflector_;
    PhotoReflector *mid_reflector_;
};

#endif //CAR_BUILDER_H

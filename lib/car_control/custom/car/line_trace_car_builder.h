#ifndef CAR_BUILDER_H
#define CAR_BUILDER_H

#include "core/component/wheel_impl.h"
#include "core/component/photo_reflector_impl.h"
#include "core/logic/brain.h"
#include "line_trace_car.h"
#include "custom/brain/line_trace_brain.h"

class LineTraceCarBuilder : public CarBuilder {
public:
    void SetLeftWheel(Wheel *wheel) override;

    void SetRightWheel(Wheel *wheel) override;

    void SetBrain(LineTraceBrain *brain);

    void SetFrontLeftReflector(PhotoReflector *reflector);

    void SetFrontRightReflector(PhotoReflector *reflector);

    void SetFrontMidReflector(PhotoReflector *reflector);

    void SetBackLeftReflector(PhotoReflector *reflector);

    void SetBackMidReflector(PhotoReflector *reflector);

    void SetBackRightReflector(PhotoReflector *reflector);

    LineTraceBrain *GetBrain();

    Wheel *GetLeftWheel() override;

    Wheel *GetRightWheel() override;

    PhotoReflector *GetFrontLeftReflector();

    PhotoReflector *GetFrontRightReflector();

    PhotoReflector *GetFrontMidReflector();

    PhotoReflector *GetBackRightReflector();

    PhotoReflector *GetBackLeftReflector();

    PhotoReflector *GetBackMidReflector();

    Car *Build() override;

private:
    LineTraceBrain *brain_;
    Wheel *left_wheel_;
    Wheel *right_wheel_;
    PhotoReflector *front_left_reflector_;
    PhotoReflector *front_right_reflector_;
    PhotoReflector *front_mid_reflector_;
    PhotoReflector *back_left_reflector_;
    PhotoReflector *back_right_reflector_;
    PhotoReflector *back_mid_reflector_;
};

#endif //CAR_BUILDER_H

#ifndef CAR_BUILDER_H
#define CAR_BUILDER_H

#include "core/component/wheel_impl.h"
#include "core/component/photo_reflector_impl.h"
#include "core/logic/brain.h"
#include "line_trace_car.h"
#include "custom/brain/line_trace_brain.h"

class LineTraceCarBuilder : public CarBuilder {
public:
    void SetBrain(LineTraceBrain *brain);

    void SetFrontLeftReflector(PhotoReflectorImpl *reflector);

    void SetFrontRightReflector(PhotoReflectorImpl *reflector);

    void SetFrontMidReflector(PhotoReflectorImpl *reflector);

    void SetBackLeftReflector(PhotoReflectorImpl *reflector);

    void SetBackMidReflector(PhotoReflectorImpl *reflector);

    void SetBackRightReflector(PhotoReflectorImpl *reflector);

    LineTraceBrain *GetBrain();

    PhotoReflectorImpl *GetFrontLeftReflector();

    PhotoReflectorImpl *GetFrontRightReflector();

    PhotoReflectorImpl *GetFrontMidReflector();

    PhotoReflectorImpl *GetBackRightReflector();

    PhotoReflectorImpl *GetBackLeftReflector();

    PhotoReflectorImpl *GetBackMidReflector();

    Car* Build() override;

private:
    LineTraceBrain *brain_;
    PhotoReflectorImpl *front_left_reflector_;
    PhotoReflectorImpl *front_right_reflector_;
    PhotoReflectorImpl *front_mid_reflector_;
    PhotoReflectorImpl *back_left_reflector_;
    PhotoReflectorImpl *back_right_reflector_;
    PhotoReflectorImpl *back_mid_reflector_;
};

#endif //CAR_BUILDER_H

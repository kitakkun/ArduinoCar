#ifndef CAR_BUILDER_H
#define CAR_BUILDER_H

#include "component/wheel/wheel.h"
#include "component/sensor/photo_reflector.h"
#include "control/brain/brain.h"

class Car;

class CarBuilder {
public:
    void SetBrain(Brain *brain);
    void SetLeftWheel(Wheel *wheel);
    void SetRightWheel(Wheel *wheel);
    void SetLeftReflector(PhotoReflector *reflector);
    void SetRightReflector(PhotoReflector *reflector);
    void SetMidReflector(PhotoReflector *reflector);
    Brain *GetBrain();
    Wheel *GetLeftWheel();
    Wheel *GetRightWheel();
    PhotoReflector *GetLeftReflector();
    PhotoReflector *GetRightReflector();
    PhotoReflector *GetMidReflector();
    Car * Build();
private:
    Brain *brain_;
    Wheel *left_wheel_;
    Wheel *right_wheel_;
    PhotoReflector *left_reflector_;
    PhotoReflector *right_reflector_;
    PhotoReflector *mid_reflector_;
};

#endif //CAR_BUILDER_H

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
    void SetFrontLeftReflector(PhotoReflector *reflector);
    void SetFrontRightReflector(PhotoReflector *reflector);
    void SetFrontMidReflector(PhotoReflector *reflector);
    void SetBackLeftReflector(PhotoReflector *reflector);
    void SetBackMidReflector(PhotoReflector *reflector);
    void SetBackRightReflector(PhotoReflector *reflector);
    Brain *GetBrain();
    Wheel *GetLeftWheel();
    Wheel *GetRightWheel();
    PhotoReflector *GetFrontLeftReflector();
    PhotoReflector *GetFrontRightReflector();
    PhotoReflector *GetFrontMidReflector();
    PhotoReflector *GetBackRightReflector();
    PhotoReflector *GetBackLeftReflector();
    PhotoReflector *GetBackMidReflector();
    Car * Build();
private:
    Brain *brain_;
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

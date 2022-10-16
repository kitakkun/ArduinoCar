#ifndef CAR_BUILDER_H
#define CAR_BUILDER_H

#include "wheel.h"
#include "photo_reflector.h"
#include "brain.h"

class Car;

class CarBuilder {
public:
    void SetBrain(Brain *brain);
    void SetLeftWheel(Wheel *wheel);
    void SetRightWheel(Wheel *wheel);
    void SetLeftReflector(PhotoReflector *reflector);
    void SetRightReflector(PhotoReflector *reflector);
    void SetFrontReflector(PhotoReflector *reflector);
    Brain *GetBrain();
    Wheel *GetLeftWheel();
    Wheel *GetRightWheel();
    PhotoReflector *GetLeftReflector();
    PhotoReflector *GetRightReflector();
    PhotoReflector *GetFrontReflector();
    Car * Build();
private:
    Brain *brain_;
    Wheel *left_wheel_;
    Wheel *right_wheel_;
    PhotoReflector *left_reflector_;
    PhotoReflector *right_reflector_;
    PhotoReflector *front_reflector_;
};

#endif //CAR_BUILDER_H

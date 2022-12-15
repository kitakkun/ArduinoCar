#ifndef LABORATORY_WORK_IN_INFORMATION_ENGINEERING_III_PHOTO_REFLECTOR_H
#define LABORATORY_WORK_IN_INFORMATION_ENGINEERING_III_PHOTO_REFLECTOR_H

#include "sensor.h"

class PhotoReflector : public Sensor {
public:
    virtual bool IsBlack() = 0;

    virtual bool IsWhite() = 0;
};

#endif
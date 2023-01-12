#ifndef LABORATORY_WORK_IN_INFORMATION_ENGINEERING_III_PHOTO_REFLECTOR_H
#define LABORATORY_WORK_IN_INFORMATION_ENGINEERING_III_PHOTO_REFLECTOR_H

#include "interface/analog_sensor.h"

class PhotoReflector : public AnalogSensor {
public:
    virtual bool IsBlack() = 0;

    virtual bool IsWhite() = 0;
};

#endif
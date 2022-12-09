#ifndef LABORATORY_WORK_IN_INFORMATION_ENGINEERING_III_PHOTO_REFLECTOR_H
#define LABORATORY_WORK_IN_INFORMATION_ENGINEERING_III_PHOTO_REFLECTOR_H

#include "sensor.h"

class PhotoReflector : public Sensor {
public:
    explicit PhotoReflector(int pin, int theta);

    bool IsBlack();

    bool IsWhite();    

private:
    int pin_;
    int theta_;     /// 閾値
    int value_;
};

#endif
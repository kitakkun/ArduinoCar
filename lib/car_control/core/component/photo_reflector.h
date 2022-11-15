#ifndef LABORATORY_WORK_IN_INFORMATION_ENGINEERING_III_PHOTO_REFLECTOR_H
#define LABORATORY_WORK_IN_INFORMATION_ENGINEERING_III_PHOTO_REFLECTOR_H


#include "sensor.h"
#include "core/data_model/binary_color.h"

class PhotoReflector : public Sensor {
public:
    virtual BinaryColor Value() = 0;
};


#endif //LABORATORY_WORK_IN_INFORMATION_ENGINEERING_III_PHOTO_REFLECTOR_H

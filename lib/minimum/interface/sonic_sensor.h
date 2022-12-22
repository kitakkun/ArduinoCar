#ifndef LABORATORY_WORK_IN_INFORMATION_ENGINEERING_III_SONIC_SENSOR_H
#define LABORATORY_WORK_IN_INFORMATION_ENGINEERING_III_SONIC_SENSOR_H

#include "interface/sensor.h"

class SonicSensor {
public:
    virtual void Update() = 0;

    virtual double GetRawValue() = 0;

    virtual void InitUpdateTask() = 0;

    virtual bool IsUpdateCompleted() = 0;
};

#endif //LABORATORY_WORK_IN_INFORMATION_ENGINEERING_III_SONIC_SENSOR_H

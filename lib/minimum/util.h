#ifndef LABORATORY_WORK_IN_INFORMATION_ENGINEERING_III_UTIL_H
#define LABORATORY_WORK_IN_INFORMATION_ENGINEERING_III_UTIL_H

#include "sensor.h"

namespace util {
    void logSensors(Sensor *left, Sensor *mid, Sensor *right);
    bool isSensorBlack(Sensor* sensor, int theta);
}

#endif //LABORATORY_WORK_IN_INFORMATION_ENGINEERING_III_UTIL_H

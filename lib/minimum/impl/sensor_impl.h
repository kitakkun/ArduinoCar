#ifndef LABORATORY_WORK_IN_INFORMATION_ENGINEERING_III_SENSOR_IMPL_H
#define LABORATORY_WORK_IN_INFORMATION_ENGINEERING_III_SENSOR_IMPL_H


#include "interface/analog_sensor.h"

class SensorImpl : public AnalogSensor {
public:
    explicit SensorImpl(int pin);

    void Update() override;

    int GetRawValue() override;

private:
    int pin_;
    int raw_value_;
};


#endif //LABORATORY_WORK_IN_INFORMATION_ENGINEERING_III_SENSOR_IMPL_H

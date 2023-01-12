#ifndef LABORATORY_WORK_IN_INFORMATION_ENGINEERING_III_DIGITAL_SENSOR_IMPL_H
#define LABORATORY_WORK_IN_INFORMATION_ENGINEERING_III_DIGITAL_SENSOR_IMPL_H


#include "interface/sensor/digital_sensor.h"

class DigitalSensorImpl : public DigitalSensor {
public:
    explicit DigitalSensorImpl(int pin);

    void Update() override;

    bool IsHigh() override;

    bool IsLow() override;

private:
    int pin_;
    bool is_high_;
};


#endif //LABORATORY_WORK_IN_INFORMATION_ENGINEERING_III_DIGITAL_SENSOR_IMPL_H

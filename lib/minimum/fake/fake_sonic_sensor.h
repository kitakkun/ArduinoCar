#ifndef LABORATORY_WORK_IN_INFORMATION_ENGINEERING_III_FAKE_SONIC_SENSOR_H
#define LABORATORY_WORK_IN_INFORMATION_ENGINEERING_III_FAKE_SONIC_SENSOR_H

#include "sonic_sensor.h"

class FakeSonicSensor : public SonicSensor {
public:
    explicit FakeSonicSensor();

    void Update() override;

    double GetRawValue() override;

    void SetRawValue(double raw_value);

private:
    double raw_value_;
};


#endif //LABORATORY_WORK_IN_INFORMATION_ENGINEERING_III_FAKE_SONIC_SENSOR_H

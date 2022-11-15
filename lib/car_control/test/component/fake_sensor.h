#ifndef LABORATORY_WORK_IN_INFORMATION_ENGINEERING_III_FAKE_SENSOR_H
#define LABORATORY_WORK_IN_INFORMATION_ENGINEERING_III_FAKE_SENSOR_H

#include "core/component/sensor.h"

class FakeSensor: public Sensor {
public:
    explicit FakeSensor();
    void Update() override;
    int RawValue() override;
    void SetRawValue(int raw_value);
private:
    int raw_value_;
};


#endif //LABORATORY_WORK_IN_INFORMATION_ENGINEERING_III_FAKE_SENSOR_H
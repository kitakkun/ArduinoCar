#ifndef LABORATORY_WORK_IN_INFORMATION_ENGINEERING_III_SONIC_SENSOR_IMPL_H
#define LABORATORY_WORK_IN_INFORMATION_ENGINEERING_III_SONIC_SENSOR_IMPL_H

#include "sonic_sensor.h"
#include "ace_routine/Coroutine.h"

class SonicSensorImpl : public SonicSensor, ace_routine::Coroutine {
public:
    explicit SonicSensorImpl(int trig_pin, int echo_pin);

    void Update() override;

    double GetRawValue() override;

private:
    int RunUpdateCoroutine();

    int trig_pin_;
    int echo_pin_;
    double raw_value_;
};

#endif //LABORATORY_WORK_IN_INFORMATION_ENGINEERING_III_SONIC_SENSOR_IMPL_H
 
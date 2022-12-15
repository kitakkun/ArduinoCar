#ifndef LABORATORY_WORK_IN_INFORMATION_ENGINEERING_III_SONIC_SENSOR_H
#define LABORATORY_WORK_IN_INFORMATION_ENGINEERING_III_SONIC_SENSOR_H


class SonicSensor : ace_routine::Coroutine {
public:
    explicit SonicSensor(int trig_pin, int echo_pin);

    int Update() override;

    float GetRawValue();

    private:
    int trig_pin_;
    int echo_pin_;
    float raw_value_;
}

#endif //LABORATORY_WORK_IN_INFORMATION_ENGINEERING_III_SONIC_SENSOR_H
 
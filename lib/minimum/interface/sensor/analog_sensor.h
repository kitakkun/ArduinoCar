#ifndef LABORATORY_WORK_IN_INFORMATION_ENGINEERING_III_ANALOG_SENSOR_H
#define LABORATORY_WORK_IN_INFORMATION_ENGINEERING_III_ANALOG_SENSOR_H


class AnalogSensor {
public:
    virtual void Update() = 0;

    virtual int GetRawValue() = 0;
};


#endif //LABORATORY_WORK_IN_INFORMATION_ENGINEERING_III_ANALOG_SENSOR_H

#ifndef LABORATORY_WORK_IN_INFORMATION_ENGINEERING_III_DIGITAL_SENSOR_H
#define LABORATORY_WORK_IN_INFORMATION_ENGINEERING_III_DIGITAL_SENSOR_H

class DigitalSensor {
public:
    virtual void Update() = 0;
    virtual bool IsHigh() = 0;
    virtual bool IsLow() = 0;
};

#endif //LABORATORY_WORK_IN_INFORMATION_ENGINEERING_III_DIGITAL_SENSOR_H

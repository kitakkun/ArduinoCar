#ifndef LABORATORY_WORK_IN_INFORMATION_ENGINEERING_III_SENSOR_H
#define LABORATORY_WORK_IN_INFORMATION_ENGINEERING_III_SENSOR_H


class Sensor {
public:
    explicit Sensor(int pin);

    void Update();

    int GetRawValue();

private:
    int pin_;
    int value_;
};


#endif //LABORATORY_WORK_IN_INFORMATION_ENGINEERING_III_SENSOR_H

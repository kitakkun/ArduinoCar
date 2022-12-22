#ifndef LABORATORY_WORK_IN_INFORMATION_ENGINEERING_III_FOLLOW_CAR_BUILDER_H
#define LABORATORY_WORK_IN_INFORMATION_ENGINEERING_III_FOLLOW_CAR_BUILDER_H


#include "interface/sonic_sensor.h"
#include "interface/motor.h"
#include "car/follow_car.h"

class FollowCarBuilder {
public:
    explicit FollowCarBuilder();

    void SetLeftMotor(Motor *left_motor);

    void SetRightMotor(Motor *right_motor);

    void SetLeftSensor(SonicSensor *left_sensor);

    void SetRightSensor(SonicSensor *right_sensor);

    FollowCar *Build();

private:
    Motor *left_motor_;
    Motor *right_motor_;
    SonicSensor *left_sensor_;
    SonicSensor *right_senor_;
};


#endif //LABORATORY_WORK_IN_INFORMATION_ENGINEERING_III_FOLLOW_CAR_BUILDER_H

#ifndef LABORATORY_WORK_IN_INFORMATION_ENGINEERING_III_FOLLOW_CAR_BUILDER_H
#define LABORATORY_WORK_IN_INFORMATION_ENGINEERING_III_FOLLOW_CAR_BUILDER_H


#include "interface/sonic_sensor.h"
#include "interface/motor.h"
#include "car/follow_car.h"

class FollowCarBuilder {
public:
    explicit FollowCarBuilder();

    FollowCarBuilder &SetLeftMotor(Motor *left_motor);

    FollowCarBuilder &SetRightMotor(Motor *right_motor);

    FollowCarBuilder &SetLeftSensor(SonicSensor *left_sensor);

    FollowCarBuilder &SetRightSensor(SonicSensor *right_sensor);

    FollowCarBuilder &SetCrashDetector(DigitalSensor *crash_detector);

    FollowCar *Build();

private:
    Motor *left_motor_;
    Motor *right_motor_;
    SonicSensor *left_sensor_;
    SonicSensor *right_senor_;
    DigitalSensor *crash_detector_;
};


#endif //LABORATORY_WORK_IN_INFORMATION_ENGINEERING_III_FOLLOW_CAR_BUILDER_H

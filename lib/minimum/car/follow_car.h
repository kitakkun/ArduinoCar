#ifndef LABORATORY_WORK_IN_INFORMATION_ENGINEERING_III_FOLLOW_CAR_H
#define LABORATORY_WORK_IN_INFORMATION_ENGINEERING_III_FOLLOW_CAR_H

#include "interface/motor.h"
#include "interface/sonic_sensor.h"

/**
 * 追従車の各コンポーネントへのアクセスを提供するクラス
 */
class FollowCar {
public:
    explicit FollowCar(
        Motor *left_motor,
        Motor *right_motor,
        SonicSensor *left_sensor,
        SonicSensor *right_sensor
    );

    Motor *GetLeftMotor();

    Motor *GetRightMotor();

    SonicSensor *GetLeftSensor();

    SonicSensor *GetRightSensor();

private:
    Motor *left_motor_;
    Motor *right_motor_;
    SonicSensor *left_sensor_;
    SonicSensor *right_sensor_;
};


#endif //LABORATORY_WORK_IN_INFORMATION_ENGINEERING_III_FOLLOW_CAR_H

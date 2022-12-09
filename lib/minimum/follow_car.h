#ifndef LABORATORY_WORK_IN_INFORMATION_ENGINEERING_III_FOLLOW_CAR_H
#define LABORATORY_WORK_IN_INFORMATION_ENGINEERING_III_FOLLOW_CAR_H

#include "motor.h"
#include "sensor.h"

/**
 * 追従車の各コンポーネントへのアクセスを提供するクラス
 */
class FollowCar {
public:
    explicit FollowCar(
            Motor *left_motor,
            Motor *right_motor,
            Sensor *left_sensor,
            Sensor *right_sensor
    );

    Motor *GetLeftMotor();

    Motor *GetRightMotor();

    Sensor *GetLeftSensor();

    Sensor *GetRightSensor();

private:
    Motor *left_motor_;
    Motor *right_motor_;
    Sensor *left_sensor_;
    Sensor *right_sensor_;
};


#endif //LABORATORY_WORK_IN_INFORMATION_ENGINEERING_III_FOLLOW_CAR_H

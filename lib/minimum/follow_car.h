#ifndef LABORATORY_WORK_IN_INFORMATION_ENGINEERING_III_FOLLOW_CAR_H
#define LABORATORY_WORK_IN_INFORMATION_ENGINEERING_III_FOLLOW_CAR_H

#include "motor_impl.h"
#include "sonic_sensor_impl.h"

/**
 * 追従車の各コンポーネントへのアクセスを提供するクラス
 */
class FollowCar {
public:
    explicit FollowCar(
        MotorImpl *left_motor,
        MotorImpl *right_motor,
        SonicSensorImpl *left_sensor,
        SonicSensorImpl *right_sensor
    );

    MotorImpl *GetLeftMotor();

    MotorImpl *GetRightMotor();

    SonicSensorImpl *GetLeftSensor();

    SonicSensorImpl *GetRightSensor();

private:
    MotorImpl *left_motor_;
    MotorImpl *right_motor_;
    SonicSensorImpl *left_sensor_;
    SonicSensorImpl *right_sensor_;
};


#endif //LABORATORY_WORK_IN_INFORMATION_ENGINEERING_III_FOLLOW_CAR_H

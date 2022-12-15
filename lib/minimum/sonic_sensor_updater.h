#ifndef LABORATORY_WORK_IN_INFORMATION_ENGINEERING_III_SONIC_SENSOR_UPDATOR_H
#define LABORATORY_WORK_IN_INFORMATION_ENGINEERING_III_SONIC_SENSOR_UPDATOR_H


#include "sonic_sensor.h"

/**
 * 音波が干渉しないように左右の超音波センサーの更新タイミングをずらすクラス
 */
class SonicSensorUpdater {
public:
    explicit SonicSensorUpdater(SonicSensor* left_sensor, SonicSensor *right_sensor);

    void Update();

private:
    SonicSensor *left_sensor_;
    SonicSensor *right_sensor_;
    SonicSensor *updating_sensor_;
};


#endif //LABORATORY_WORK_IN_INFORMATION_ENGINEERING_III_SONIC_SENSOR_UPDATOR_H

#ifndef LABORATORY_WORK_IN_INFORMATION_ENGINEERING_III_SONIC_SENSOR_UPDATOR_H
#define LABORATORY_WORK_IN_INFORMATION_ENGINEERING_III_SONIC_SENSOR_UPDATOR_H


#include "impl.h"

/**
 * 音波が干渉しないように左右の超音波センサーの更新タイミングをずらすクラス
 */
class SonicSensorUpdater {
public:
    explicit SonicSensorUpdater(SonicSensorImpl* left_sensor, SonicSensorImpl *right_sensor);

    void Update();

private:
    SonicSensorImpl *left_sensor_;
    SonicSensorImpl *right_sensor_;
    SonicSensorImpl *updating_sensor_;
};


#endif //LABORATORY_WORK_IN_INFORMATION_ENGINEERING_III_SONIC_SENSOR_UPDATOR_H

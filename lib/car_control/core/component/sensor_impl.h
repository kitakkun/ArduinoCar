#ifndef LABORATORY_WORK_IN_INFORMATION_ENGINEERING_III_SENSOR_IMPL_H
#define LABORATORY_WORK_IN_INFORMATION_ENGINEERING_III_SENSOR_IMPL_H

#include "core/debug/debuggable.h"
#include "sensor.h"

/**
 * センサークラス
 * センサー値の更新・保持・提供を行う
 */
class SensorImpl : public Sensor, public Debuggable {
public:
    explicit SensorImpl(int pin, String tag="SensorImpl");

    void Update() override;

    int RawValue() override;
private:
    int pin_;       /// センサーのピン番号
    int raw_value_;     /// センサーの値
    String tag_;
};

#endif //LABORATORY_WORK_IN_INFORMATION_ENGINEERING_III_SENSOR_IMPL_H

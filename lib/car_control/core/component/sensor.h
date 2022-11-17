#ifndef SENSOR_DATA_H
#define SENSOR_DATA_H

#include "core/debug/debuggable.h"

/**
 * センサークラス
 * センサー値の更新・保持・提供を行う
 */
class Sensor {
public:
    /**
     * センサー値を更新
     */
    virtual void Update() = 0;

    /**
     * センサー値の取得（生のデータ）
     * @return 生のセンサー値
     */
    virtual int RawValue() = 0;
};

#endif

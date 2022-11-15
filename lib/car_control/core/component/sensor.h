#ifndef SENSOR_DATA_H
#define SENSOR_DATA_H

#include "core/debug/debuggable.h"

/**
 * センサークラス
 * センサー値の更新・保持・提供を行う
 */
class Sensor : public Debuggable {
public:
    /**
     * コンストラクタ
     * @param pin ピン番号
     */
    explicit Sensor(int pin, String tag="Sensor");

    /**
     * センサー値を更新
     */
    void Update();

    /**
     * センサー値の取得（生のデータ）
     * @return 生のセンサー値
     */
    int RawValue() const;

    String Tag() override;

private:
    int pin_;       /// センサーのピン番号
    int raw_value_;     /// センサーの値
    String tag_;
};

#endif

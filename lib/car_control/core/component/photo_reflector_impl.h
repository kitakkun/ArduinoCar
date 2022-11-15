#ifndef LINE_SENSOR_ADAPTER_H
#define LINE_SENSOR_ADAPTER_H

#include "sensor.h"
#include "core/data_model/binary_color.h"
#include "sensor_impl.h"
#include "photo_reflector.h"

/**
 * フォトリフレクタに対応するセンサークラス
 */
class PhotoReflectorImpl : public PhotoReflector, public Debuggable {
public:
    explicit PhotoReflectorImpl(int pin, int theta, String tag="PhotoReflectorImpl");

    void Update() override;

    int RawValue() override;

    BinaryColor Value() override;

private:
    int pin_;
    int theta_;      /// 白か黒か判定する閾値
    int raw_value_;
    BinaryColor value_;
};

#endif

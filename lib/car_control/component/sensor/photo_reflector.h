#ifndef LINE_SENSOR_ADAPTER_H
#define LINE_SENSOR_ADAPTER_H

#include "sensor.h"
#include "../../model/paper_color.h"

/**
 * フォトリフレクタに対応するセンサークラス
 */
class PhotoReflector : public Sensor {
public:
    /**
     * コンストラクタ
     * @param pin ピン番号
     * @param theta 白黒の閾値
     */
    PhotoReflector(int pin, int theta);

    /**
     * センサーが認識した色を取得
     * @return 認識した色（白・黒）
     */
    PaperColor Value() const;

private:
    int theta_;      /// 白か黒か判定する閾値
};

#endif

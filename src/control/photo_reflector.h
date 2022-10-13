#ifndef LINE_SENSOR_ADAPTER_H
#define LINE_SENSOR_ADAPTER_H

#include "sensor.h"
#include "paper_color.h"

/**
 * フォトリフレクタ（ライン検出用センサ）
 */
class PhotoReflector : Sensor {
    public:
        PhotoReflector(int pin, int theta);
        PaperColor Value();
    private:
        int theta_;         // 白か黒か判定する境目
};

#endif
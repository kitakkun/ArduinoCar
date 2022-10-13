#ifndef LINE_SENSOR_ADAPTER_H
#define LINE_SENSOR_ADAPTER_H

#include "sensor.h"
#include "paper_color.h"

/**
 * ライン検出用センサー
 */
class LineSensorAdapter {
    public:
        LineSensorAdapter(int pin, int theta);
        void Update();
        PaperColor CurrentValue();
    private:
        Sensor *sensor_;
        int theta_;         // 白か黒か判定する境目
};

#endif

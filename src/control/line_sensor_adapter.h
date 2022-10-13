#ifndef LINE_SENSOR_ADAPTER_H
#define LINE_SENSOR_ADAPTER_H

#include "sensor.h"
#include "paper_color.h"

/**
 * ライン検出用センサー
 */
class LineSensorAdapter {
    public:
        LineSensorAdapter(int pin);
        void Update();
        PaperColor CurrentValue();
    private:
        Sensor *sensor_;
};

#endif

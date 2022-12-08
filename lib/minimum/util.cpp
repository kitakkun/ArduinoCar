#include "util.h"
#include "ArduinoLog.h"

namespace util {
    // センサー値をログ出力
    void logSensors(Sensor *left, Sensor *mid, Sensor *right) {
        Log.verboseln(
                "%d %d %d",
                left->GetRawValue(),
                mid->GetRawValue(),
                right->GetRawValue()
        );
    }

    // センサー値を白黒で判定
    bool isSensorBlack(Sensor* sensor, int theta) {
        return sensor->GetRawValue() > theta;
    }
}
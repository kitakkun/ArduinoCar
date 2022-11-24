#include "sensor_debugger.h"
#include "ArduinoLog.h"

SensorDebugger::SensorDebugger(Sensor *mid_sensor, Sensor *left_sensor, Sensor *right_sensor) {
    this->mid_sensor_ = mid_sensor;
    this->left_sensor_ = left_sensor;
    this->right_sensor_ = right_sensor;
}

void SensorDebugger::LogValues() {
    Log.verboseln(
            "[SensorDebugger] left: %d, right: %d, mid: %d",
            this->left_sensor_->RawValue(),
            this->right_sensor_->RawValue(),
            this->mid_sensor_->RawValue()
    );
}

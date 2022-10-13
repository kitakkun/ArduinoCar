#include "line_sensor_adapter.h"

// ライン検出用センサーのコンストラクタ
LineSensorAdapter::LineSensorAdapter(int pin) {
    this->sensor_ = new Sensor(pin);
}

// ライン検出センサーの値更新
void LineSensorAdapter::Update() {
    this->sensor_->Update();
}

// ライン検出センサーの値取得
PaperColor LineSensorAdapter::CurrentValue() {
    return this->sensor_->CurrentValue();
}

#include "line_sensor_adapter.h"

// ライン検出用センサーのコンストラクタ
LineSensorAdapter::LineSensorAdapter(int pin, int theta) {
    this->sensor_ = new Sensor(pin);
    this->theta_ = theta;
}

// ライン検出センサーの値更新
void LineSensorAdapter::Update() {
    this->sensor_->Update();
}

// ライン検出センサーの値取得
PaperColor LineSensorAdapter::CurrentValue() {
    int value = this->sensor_->CurrentValue();
    if (value > this->theta_) {
        return black;
    } else {
        return white;
    }
}

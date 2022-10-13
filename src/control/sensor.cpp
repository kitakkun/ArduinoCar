#include "sensor.h"
#include <Arduino.h>

// センサーの初期化
Sensor::Sensor(int pin) {
    this->pin_ = pin;
}

// センサーの更新
void Sensor::Update() {
    this->value_ = analogRead(this->pin_);
}

// センサーの現在の値を取得
int Sensor::CurrentValue() {
    return this->value_;
}

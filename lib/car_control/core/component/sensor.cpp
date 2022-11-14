#include "sensor.h"
#include <Arduino.h>

// センサーの初期化
Sensor::Sensor(int pin) {
    this->pin_ = pin;
    this->value_ = 0;
    pinMode(this->pin_, INPUT);
}

// センサーの更新
void Sensor::Update() {
    this->value_ = analogRead(this->pin_);
}

// センサーの現在の値を取得
int Sensor::RawValue() const {
    return this->value_;
}

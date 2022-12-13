#include "sensor.h"
#include <Arduino.h>

/* TODO: ここに各メソッドを実装する */

// センサーの初期化
Sensor::Sensor(int pin) {
    this->pin_ = pin;
    this->raw_value_ = 0;
    pinMode(this->pin_, INPUT);
}

// センサーの更新
void Sensor::Update() {
    this->raw_value_ = analogRead(this->pin_);
}

// センサーの現在の値を取得
int Sensor::GetRawValue() {
    return this->raw_value_;
}

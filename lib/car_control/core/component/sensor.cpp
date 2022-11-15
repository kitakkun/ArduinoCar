#include "sensor.h"
#include "core/debug/logger.h"
#include <Arduino.h>

// センサーの初期化
Sensor::Sensor(int pin, String tag) {
    this->pin_ = pin;
    this->raw_value_ = 0;
    this->tag_ = tag;
    pinMode(this->pin_, INPUT);
}

// センサーの更新
void Sensor::Update() {
    this->raw_value_ = analogRead(this->pin_);
    Logger::Verboseln(this, "Updated. New value is %d", raw_value_);
}

// センサーの現在の値を取得
int Sensor::RawValue() const {
    return this->raw_value_;
}

String Sensor::Tag() {
    return this->tag_;
}


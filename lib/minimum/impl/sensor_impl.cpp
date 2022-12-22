#include <Arduino.h>
#include "sensor_impl.h"

SensorImpl::SensorImpl(int pin) {
    this->pin_ = pin;
    this->raw_value_ = 0;
    pinMode(this->pin_, INPUT);
}

// センサーの更新
void SensorImpl::Update() {
    this->raw_value_ = analogRead(this->pin_);
}

// センサーの現在の値を取得
int SensorImpl::GetRawValue() {
    return this->raw_value_;
}

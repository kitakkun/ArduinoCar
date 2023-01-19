#include <Arduino.h>
#include "analog_sensor_impl.h"

AnalogSensorImpl::AnalogSensorImpl(int pin) {
    this->pin_ = pin;
    this->raw_value_ = 0;
    pinMode(this->pin_, INPUT);
}

// センサーの更新
void AnalogSensorImpl::Update() {
    this->raw_value_ = analogRead(this->pin_);
}

// センサーの現在の値を取得
int AnalogSensorImpl::GetRawValue() {
    return this->raw_value_;
}

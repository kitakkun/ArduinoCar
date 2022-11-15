#include "sensor_impl.h"
#include "core/debug/logger.h"
#include <Arduino.h>

// センサーの初期化
SensorImpl::SensorImpl(int pin, String tag) : Debuggable(tag, true) {
    this->pin_ = pin;
    this->raw_value_ = 0;
    pinMode(this->pin_, INPUT);
    Logger::Verboseln(this, F("Instantiated"));
}

// センサーの更新
void SensorImpl::Update() {
    this->raw_value_ = analogRead(this->pin_);
    Logger::Verboseln(this, F("Updated. New value is %d"), raw_value_);
}

// センサーの現在の値を取得
int SensorImpl::RawValue() {
    return this->raw_value_;
}


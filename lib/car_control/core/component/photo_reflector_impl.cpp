#include <Arduino.h>
#include "photo_reflector_impl.h"
#include "core/debug/logger.h"

// フォトリフレクタのコンストラクタ
PhotoReflectorImpl::PhotoReflectorImpl(int pin, int theta, String tag) : Debuggable(tag) {
    this->pin_ = pin;
    this->theta_ = theta;
    this->value_ = white;
    raw_value_ = 0;
    pinMode(pin_, INPUT);
}

// フォトリフレクタの値取得（黒か白）
BinaryColor PhotoReflectorImpl::Value() {
    return value_;
}

void PhotoReflectorImpl::Update() {
    raw_value_ = analogRead(pin_);
//    Logger::Verboseln(this, F("Updated. New value is %d"), raw_value_);
    if (raw_value_ > this->theta_) {
        value_ = black;
    } else {
        value_ = white;
    }
}

int PhotoReflectorImpl::RawValue() {
    return raw_value_;
}

#include <Arduino.h>
#include "photo_reflector.h"

// フォトリフレクタのコンストラクタ
PhotoReflector::PhotoReflector(int pin, int theta) : Sensor(pin) {
    this->pin_ = pin;
    this->theta_ = theta;
    this->value_ = 0;
    pinMode(pin_, INPUT);
}

bool PhotoReflector::IsBlack() {
    value_ = this->GetRawValue();
    if (value_ > this->theta_) {
        return true;
    } else {
        return false;
    }
}

bool PhotoReflector::IsWhite() {
    return !this->IsBlack();
}

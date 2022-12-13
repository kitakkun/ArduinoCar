#include <Arduino.h>
#include "photo_reflector.h"

// フォトリフレクタのコンストラクタ
PhotoReflector::PhotoReflector(int pin, int theta) : Sensor(pin) {
    this->theta_ = theta;
    this->is_black_ = false;
}

void PhotoReflector::Update() {
    Sensor::Update();
    this->is_black_ = this->GetRawValue() > this->theta_;
}

bool PhotoReflector::IsBlack() {
    return this->is_black_;
}

bool PhotoReflector::IsWhite() {
    return !this->is_black_;
}

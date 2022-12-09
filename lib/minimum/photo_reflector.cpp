#include <Arduino.h>
#include "photo_reflector.h"

// フォトリフレクタのコンストラクタ
PhotoReflector::PhotoReflector(int theta) : Sensor() {
    this->theta_ = theta;
}

bool PhotoReflector::IsBlack() {
    return this->GetRawValue() > this->theta_;
}

bool PhotoReflector::IsWhite() {
    return !this->IsBlack();
}

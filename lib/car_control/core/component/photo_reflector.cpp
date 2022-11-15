#include "photo_reflector.h"

// フォトリフレクタのコンストラクタ
PhotoReflector::PhotoReflector(int pin, int theta, String tag) : Sensor(pin, tag) {
    this->theta_ = theta;
    this->value_ = black;
}

// フォトリフレクタの値取得（黒か白）
BinaryColor PhotoReflector::Value() const {
    return value_;
}

void PhotoReflector::Update() {
    Sensor::Update();
    int raw = RawValue();
    if (raw > this->theta_) {
        value_ = black;
    } else {
        value_ = white;
    }
}

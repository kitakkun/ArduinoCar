#include "photo_reflector.h"

// フォトリフレクタのコンストラクタ
PhotoReflector::PhotoReflector(int pin, int theta) : Sensor(pin) {
    this->theta_ = theta;
}

// フォトリフレクタの値取得（黒か白）
PaperColor PhotoReflector::Value() const {
    int value = this->RawValue();
    if (value > this->theta_) {
        return white;
    } else {
        return black;
    }
}

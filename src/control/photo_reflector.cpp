#include "photo_reflector.h"

// フォトリフレクタのコンストラクタ
PhotoReflector::PhotoReflector(int pin, int theta) : Sensor(pin) {
    this->theta_ = theta;
}

// フォトリフレクタの値取得（黒か白）
PaperColor PhotoReflector::Value() {
    int value = this->RawValue();
    if (value > this->theta_) {
        return black;
    } else {
        return white;
    }
}

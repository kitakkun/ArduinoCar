#include "photo_reflector_impl.h"

// フォトリフレクタのコンストラクタ
PhotoReflectorImpl::PhotoReflectorImpl(int pin, int theta) : SensorImpl(pin) {
    this->theta_ = theta;
    this->is_black_ = false;
}

void PhotoReflectorImpl::Update() {
    SensorImpl::Update();
    this->is_black_ = SensorImpl::GetRawValue() > this->theta_;
}

bool PhotoReflectorImpl::IsBlack() {
    return this->is_black_;
}

bool PhotoReflectorImpl::IsWhite() {
    return !this->is_black_;
}

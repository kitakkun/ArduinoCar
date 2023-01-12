#include "photo_reflector_impl.h"

PhotoReflectorImpl::PhotoReflectorImpl(int pin, int theta) : AnalogSensorImpl(pin) {
    this->theta_ = theta;
    this->is_black_ = false;
}

void PhotoReflectorImpl::Update() {
    AnalogSensorImpl::Update();
    this->is_black_ = AnalogSensorImpl::GetRawValue() > this->theta_;
}

int PhotoReflectorImpl::GetRawValue() {
    return AnalogSensorImpl::GetRawValue();
}

bool PhotoReflectorImpl::IsBlack() {
    return this->is_black_;
}

bool PhotoReflectorImpl::IsWhite() {
    return !this->is_black_;
}

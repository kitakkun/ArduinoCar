#include "fake_photo_reflector.h"

FakePhotoReflector::FakePhotoReflector(int theta) {
    raw_value_ = 0;
    value_ = white;
    theta_ = theta;
}

void FakePhotoReflector::Update() {
    // do nothing
}

BinaryColor FakePhotoReflector::Value() {
    return value_;
}

int FakePhotoReflector::RawValue() {
    return raw_value_;
}

void FakePhotoReflector::SetRawValue(int raw_value) {
    this->raw_value_ = raw_value;
    if (this->raw_value_ > theta_) {
        value_ = black;
    } else {
        value_ = white;
    }
}


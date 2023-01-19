#include "fake_reflector.h"

FakeReflector::FakeReflector(int theta) {
    this->theta_ = theta;
}

int FakeReflector::GetRawValue() {
    return FakeSensor::GetRawValue();
}

void FakeReflector::Update() {
    // do nothing...
}

bool FakeReflector::IsBlack() {
    return GetRawValue() > this->theta_;
}

bool FakeReflector::IsWhite() {
    return !IsBlack();
}

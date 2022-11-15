#include "fake_sensor.h"

FakeSensor::FakeSensor() {
    raw_value_ = 0;
}

void FakeSensor::Update() {
    // Do nothing...
}

int FakeSensor::RawValue() {
    return raw_value_;
}

void FakeSensor::SetRawValue(int raw_value) {
    this->raw_value_ = raw_value;
}

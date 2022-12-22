#include "fake_sonic_sensor.h"

void FakeSonicSensor::Update() {
    // do nothing...
}

double FakeSonicSensor::GetRawValue() {
    return this->raw_value_;
}

void FakeSonicSensor::SetRawValue(double raw_value) {
    this->raw_value_ = raw_value;
}

FakeSonicSensor::FakeSonicSensor() {
    this->raw_value_ = 0;
}

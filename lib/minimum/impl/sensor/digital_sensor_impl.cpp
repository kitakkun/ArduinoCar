#include "digital_sensor_impl.h"
#include <Arduino.h>

DigitalSensorImpl::DigitalSensorImpl(int pin) {
    this->pin_ = pin;
    this->is_high_ = false;
    pinMode(this->pin_, INPUT);
}

void DigitalSensorImpl::Update() {
    this->is_high_ = digitalRead(this->pin_) == HIGH;
}

bool DigitalSensorImpl::IsHigh() {
    return this->is_high_;
}

bool DigitalSensorImpl::IsLow() {
    return !this->IsHigh();
}

#include <Arduino.h>
#include "led_impl.h"

LedImpl::LedImpl(int pin) {
    this->pin_ = pin;
    this->is_on_ = false;
    pinMode(this->pin_, OUTPUT);
    Apply();
}

void LedImpl::TurnOn() {
    this->is_on_ = true;
    Apply();
}

void LedImpl::TurnOff() {
    this->is_on_ = false;
    Apply();
}

void LedImpl::Toggle() {
    this->is_on_ = !this->is_on_;
    Apply();
}

bool LedImpl::IsOn() {
    return this->is_on_;
}

void LedImpl::Apply() {
    if (this->is_on_) {
        digitalWrite(this->pin_, HIGH);
    } else {
        digitalWrite(this->pin_, LOW);
    }
}

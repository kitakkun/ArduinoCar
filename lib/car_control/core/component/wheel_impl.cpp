#include "wheel_impl.h"
#include <ArduinoLog.h>
#include <Arduino.h>

// タイヤのコンストラクタ
WheelImpl::WheelImpl(int plus_pin, int minus_pin, int pwm_pin, int speed_gain) {
    this->plus_pin_ = plus_pin;
    this->minus_pin_ = minus_pin;
    this->pwm_pin_ = pwm_pin;
    this->speed_ = 0;
    this->speed_gain_ = speed_gain;
    this->direction_ = forward;
    pinMode(this->plus_pin_, OUTPUT);
    pinMode(this->minus_pin_, OUTPUT);
    pinMode(this->pwm_pin_, OUTPUT);
}

// 現在の進行方向を返す
MoveDirection WheelImpl::Direction() {
    return this->direction_;
}

// 現在のスピードを返す
int WheelImpl::Speed() {
    return this->speed_;
}

void WheelImpl::UpdateSpeed(int speed) {
    this->speed_ = speed;
    ApplySpeed();
}

void WheelImpl::UpdateDeltaSpeed(int delta_speed) {
    this->speed_ += delta_speed;
    ApplySpeed();
}

void WheelImpl::UpdateDirection(MoveDirection direction) {
    this->direction_ = direction;
    ApplyDirection();
}

void WheelImpl::ApplySpeed() const {
    if (this->speed_ > WHEEL_MAX_SPEED || this->speed_ < WHEEL_MIN_SPEED) {
        Log.warningln(
                "Invalid speed. It must be between %d and %d. Automatically fixed.",
                WHEEL_MIN_SPEED, WHEEL_MAX_SPEED
        );
    }
    analogWrite(this->pwm_pin_, constrain(this->speed_ + this->speed_gain_, WHEEL_MIN_SPEED, WHEEL_MAX_SPEED));
}

void WheelImpl::ApplyDirection() {
    if (this->direction_ == forward) {
        digitalWrite(this->plus_pin_, HIGH);
        digitalWrite(this->minus_pin_, LOW);
    } else {
        digitalWrite(this->plus_pin_, LOW);
        digitalWrite(this->minus_pin_, HIGH);
    }
}


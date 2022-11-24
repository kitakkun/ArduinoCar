#include "wheel_impl.h"
#include "core/debug/logger.h"
#include <Arduino.h>

// タイヤのコンストラクタ
WheelImpl::WheelImpl(int plus_pin, int minus_pin, int pwm_pin, String tag) : Debuggable(tag, true) {
    this->plus_pin_ = plus_pin;
    this->minus_pin_ = minus_pin;
    this->pwm_pin_ = pwm_pin;
    this->speed_ = 0;
    this->direction_ = forward;
    pinMode(this->plus_pin_, OUTPUT);
    pinMode(this->minus_pin_, OUTPUT);
    pinMode(this->pwm_pin_, OUTPUT);
    ApplySpeed();
    ApplyDirection();
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

void WheelImpl::ApplySpeed() {
//    Logger::Verboseln(this, F("Speed Updated. New speed is %d"), this->speed_);
    analogWrite(this->pwm_pin_, this->speed_);
}

void WheelImpl::ApplyDirection() {
    if (this->direction_ == forward) {
        digitalWrite(this->plus_pin_, HIGH);
        digitalWrite(this->minus_pin_, LOW);
//        Logger::Verboseln(this, F("Direction Updated. New Direction is forward"));
    } else {
        digitalWrite(this->plus_pin_, LOW);
        digitalWrite(this->minus_pin_, HIGH);
//        Logger::Verboseln(this, F("Direction Updated. New Direction is backward"));
    }
}


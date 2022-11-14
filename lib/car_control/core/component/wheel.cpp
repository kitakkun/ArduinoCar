#include "wheel.h"
#include <Arduino.h>

// タイヤのコンストラクタ
Wheel::Wheel(int plus_pin, int minus_pin, int pwm_pin) {
    this->plus_pin_ = plus_pin;
    this->minus_pin_ = minus_pin;
    this->pwm_pin_ = pwm_pin;
    this->speed_ = 0;
    pinMode(this->plus_pin_, OUTPUT);
    pinMode(this->minus_pin_, OUTPUT);
    pinMode(this->pwm_pin_, OUTPUT);
}

// 現在の進行方向を返す
MoveDirection Wheel::Direction() {
    return this->direction_;
}

// 現在のスピードを返す
int Wheel::Speed() const {
    return this->speed_;
}

void Wheel::UpdateSpeed(signed int speed) {
    this->speed_ = speed;
    ApplySpeed();
}

void Wheel::UpdateDirection(MoveDirection direction) {
    this->direction_ = direction;
    ApplyDirection();
}

void Wheel::ApplySpeed() const {
    analogWrite(this->pwm_pin_, this->speed_);
}

void Wheel::ApplyDirection() {
    if (this->direction_ == forward) {
        digitalWrite(this->plus_pin_, HIGH);
        digitalWrite(this->minus_pin_, LOW);
    } else {
        digitalWrite(this->plus_pin_, LOW);
        digitalWrite(this->minus_pin_, HIGH);
    }
}

void Wheel::UpdateDeltaSpeed(int delta_speed) {
    this->speed_ += delta_speed;
    ApplySpeed();
}

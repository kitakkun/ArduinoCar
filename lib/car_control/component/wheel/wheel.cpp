#include "wheel.h"
#include <Arduino.h>

// タイヤのコンストラクタ
Wheel::Wheel(int plus_pin, int minus_pin, int pwm_pin) {
    this->plus_pin_ = plus_pin;
    this->minus_pin_ = minus_pin;
    this->pwm_pin_ = pwm_pin;
    this->speed_ = 0;
}

// 現在の進行方向を返す
MoveDirection Wheel::Direction() {
    return this->direction_;
}

// 現在のスピードを返す
int Wheel::Speed() {
    return this->speed_;
}

void Wheel::UpdateSpeed(signed int speed) {
    this->speed_ = speed;
}

// 加速
void Wheel::Accelerate(signed int amount) {
    this->speed_ += amount;
}

// 減速
void Wheel::Decelerate(signed int amount) {
    this->speed_ -= amount;
}

void Wheel::Apply() {
    if (this->direction_ == forward) {
        digitalWrite(this->plus_pin_, HIGH);
        digitalWrite(this->minus_pin_, LOW);
    } else {
        digitalWrite(this->plus_pin_, LOW);
        digitalWrite(this->minus_pin_, HIGH);
    }
    analogWrite(this->pwm_pin_, this->speed_);
}

void Wheel::UpdateDirection(MoveDirection direction) {
    this->direction_ = direction;
}

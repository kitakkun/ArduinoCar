#include "wheel.h"
#include "core/debug/logger.h"
#include <Arduino.h>

// タイヤのコンストラクタ
Wheel::Wheel(int plus_pin, int minus_pin, int pwm_pin, String tag) : Debuggable(tag, true) {
    this->plus_pin_ = plus_pin;
    this->minus_pin_ = minus_pin;
    this->pwm_pin_ = pwm_pin;
    this->speed_ = 0;
    this->direction_ = forward;
    pinMode(this->plus_pin_, OUTPUT);
    pinMode(this->minus_pin_, OUTPUT);
    pinMode(this->pwm_pin_, OUTPUT);
    Logger::Verboseln(this, "Instantiated");
}

// 現在の進行方向を返す
MoveDirection Wheel::Direction() {
    return this->direction_;
}

// 現在のスピードを返す
int Wheel::Speed() const {
    return this->speed_;
}

void Wheel::UpdateSpeed(int speed) {
    this->speed_ = speed;
    ApplySpeed();
}

void Wheel::UpdateDeltaSpeed(int delta_speed) {
    this->speed_ += delta_speed;
    ApplySpeed();
}

void Wheel::UpdateDirection(MoveDirection direction) {
    this->direction_ = direction;
    ApplyDirection();
}

void Wheel::ApplySpeed() {
    // コルーチンから呼び出される関数でLog出力するとバグる（？）ので特別な場合を除きコメントアウトしておく
//    Logger::Verboseln(this, "Speed Updated. New speed is %d", this->speed_);
    analogWrite(this->pwm_pin_, this->speed_);
}

void Wheel::ApplyDirection() {
    if (this->direction_ == forward) {
        digitalWrite(this->plus_pin_, HIGH);
        digitalWrite(this->minus_pin_, LOW);
//        Logger::Verboseln(this, "Direction Updated. New Direction is forward");
    } else {
        digitalWrite(this->plus_pin_, LOW);
        digitalWrite(this->minus_pin_, HIGH);
//        Logger::Verboseln(this, "Direction Updated. New Direction is backward");
    }
}


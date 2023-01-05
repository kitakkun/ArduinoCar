#include "motor_impl.h"
#include <Arduino.h>

MotorImpl::MotorImpl(int plus_pin, int minus_pin, int pwm_pin, int gain) {
    this->plus_pin_ = plus_pin;
    this->minus_pin_ = minus_pin;
    this->pwm_pin_ = pwm_pin;
    this->gain_ = gain;
    this->speed_ = 0;
    this->direction_ = forward;
    pinMode(this->plus_pin_, OUTPUT);
    pinMode(this->minus_pin_, OUTPUT);
    pinMode(this->pwm_pin_, OUTPUT);
    Apply();
}

MoveDirection MotorImpl::GetMoveDirection() {
    return this->direction_;
}

int MotorImpl::GetSpeed() {
    return this->speed_;
}

void MotorImpl::UpdateSpeed(int speed) {
    this->speed_ = speed;
    Apply();
}

void MotorImpl::UpdateDirection(MoveDirection direction) {
    this->direction_ = direction;
    Apply();
}

void MotorImpl::Apply() {
    if (this->isDone()) {
        this->reset();
    }
    runCoroutine();
}

int MotorImpl::runCoroutine() {
    int speed = constrain(this->speed_ + this->gain_, 0, 255);
    COROUTINE_BEGIN();
    analogWrite(this->pwm_pin_, speed);
    if (this->direction_ == forward) {
        digitalWrite(this->plus_pin_, HIGH);
        digitalWrite(this->minus_pin_, LOW);
    } else {
        digitalWrite(this->plus_pin_, LOW);
        digitalWrite(this->minus_pin_, HIGH);
    }
    COROUTINE_DELAY(10);
    COROUTINE_END();
}

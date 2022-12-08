#include "motor.h"

/* TODO: 各メソッドの実装 */
Moter::Moter(int plus_pin, int minus_pin, int pwm_pin){
    this->plus_pin_ = plus_pin;
    this->minus_pin_ = minus_pin;
    this->pwm_pin_ = pwm_pin;
    this->speed_ = 0;
    this->direction_ = forward;
    pinMode(this->plus_pin_, OUTPUT);
    pinMode(this->minus_pin_, OUTPUT);
    pinMode(this->pwm_pin_, OUTPUT);
}

MoterDirection Moter::GetMoveDirection(){
    return this->direction_;
}

int Moter::GetSpeed(){
    return this->speed_;
}

void Moter::UpdateSpeed(int speed){
    this->speed_ = speed;
    ApplySpeed();
}

void Moter::UpdateDirection(MoveDirection direction){
    this->direction_ = direction;
    ApplyDirection();
}

void Moter::ApplySpeed() {
    analogWrite(this->pwm_pin_, this->speed_);
}

void Moter::ApplyDirection() {
    if (this->direction_ == forward) {
        digitalWrite(this->plus_pin_, HIGH);
        digitalWrite(this->minus_pin_, LOW);
    } else {
        digitalWrite(this->plus_pin_, LOW);
        digitalWrite(this->minus_pin_, HIGH);
    }
}

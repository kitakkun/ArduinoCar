#include "motor.h"
#include <Arduino.h>

/* TODO: 各メソッドの実装 */
Motor::Motor(int plus_pin, int minus_pin, int pwm_pin, int gain){
    this->plus_pin_ = plus_pin;
    this->minus_pin_ = minus_pin;
    this->pwm_pin_ = pwm_pin;
    this->gain_ = gain;
    this->speed_ = 0;
    this->direction_ = forward;
    pinMode(this->plus_pin_, OUTPUT);
    pinMode(this->minus_pin_, OUTPUT);
    pinMode(this->pwm_pin_, OUTPUT);
}

MoveDirection Motor::GetMoveDirection(){
    return this->direction_;
}

int Motor::GetSpeed(){
    return this->speed_;
}

void Motor::UpdateSpeed(int speed){
    this->speed_ = speed;
    ApplySpeed();
}

void Motor::UpdateDirection(MoveDirection direction){
    this->direction_ = direction;
    ApplyDirection();
}

void Motor::ApplySpeed() {
    int speed=constrain(this->speed_ + this->gain_, 0, 255);
    analogWrite(this->pwm_pin_, speed);
}

void Motor::ApplyDirection() {
    if (this->direction_ == forward) {
        digitalWrite(this->plus_pin_, HIGH);
        digitalWrite(this->minus_pin_, LOW);
    } else {
        digitalWrite(this->plus_pin_, LOW);
        digitalWrite(this->minus_pin_, HIGH);
    }
}

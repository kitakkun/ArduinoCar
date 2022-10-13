#include "wheel.h"

// タイヤのコンストラクタ
Wheel::Wheel(int plus_pin, int minus_pin, int pwm_pin) {
    this->plus_pin_ = plus_pin;
    this->minus_pin_ = minus_pin;
    this->pwm_pin_ = pwm_pin;
}

// 現在の進行方向を返す
MoveDirection Wheel::Direction() {
    return this->direction_;
}

// 現在のスピードを返す
int Wheel::Speed() {
    return this->speed_;
}

void Wheel::UpdateSpeed(int speed, int milliseconds) {
    // TODO: 速度を指定時間かけてゆっくり変化させる処理
}



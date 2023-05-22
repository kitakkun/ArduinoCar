#include "sonic_sensor_impl.h"
#include <Arduino.h>

SonicSensorImpl::SonicSensorImpl(int trig_pin, int echo_pin, double min_value, double max_value) {
    this->trig_pin_ = trig_pin;
    this->echo_pin_ = echo_pin;
    this->min_value_ = min_value;
    this->max_value_ = max_value;
    this->last_updated_time_ = millis();
    pinMode(this->trig_pin_, OUTPUT);
    pinMode(this->echo_pin_, INPUT);
}

bool SonicSensorImpl::Update() {

    // 最終更新から60ms経過するまで次の更新タスクを実行しない
    if (millis() - last_updated_time_ < 60) {
        return false;
    }

    //念のために最初に超音波を止める
    digitalWrite(this->trig_pin_, LOW);
    delayMicroseconds(2);
    digitalWrite(this->trig_pin_, HIGH);
    delayMicroseconds(10);
    digitalWrite(this->trig_pin_, LOW);

    //帰ってくるまでの時間を計測
    unsigned long duration = pulseIn(this->echo_pin_, HIGH) / 2;

    //距離の計算
    this->raw_value_ = constrain(
        (double) duration * 340.0 / 10000.0,
        this->min_value_,
        this->max_value_
    );

    this->last_updated_time_ = millis();
    return true;
}

//センサーの現在の値を取得
double SonicSensorImpl::GetRawValue() {
    return this->raw_value_;
}

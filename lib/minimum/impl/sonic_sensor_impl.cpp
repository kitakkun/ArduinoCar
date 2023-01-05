#include "sonic_sensor_impl.h"
#include <Arduino.h>

SonicSensorImpl::SonicSensorImpl(int trig_pin, int echo_pin) {
    this->trig_pin_ = trig_pin;
    this->echo_pin_ = echo_pin;
    this->last_updated_time_ = millis();
    pinMode(this->trig_pin_, OUTPUT);
    pinMode(this->echo_pin_, INPUT);
}

bool SonicSensorImpl::IsUpdateCompleted() {
    return this->isDone();
}

void SonicSensorImpl::InitUpdateTask() {
    this->reset();
}

void SonicSensorImpl::Update() {
    this->runCoroutine();
}

//センサーの現在の値を取得
double SonicSensorImpl::GetRawValue() {
    return this->raw_value_;
}

int SonicSensorImpl::runCoroutine() {
    unsigned long duration;
    COROUTINE_BEGIN();

    // 最終更新から60ms経過するまで次の更新タスクを実行しない
    while(millis() - last_updated_time_ < 60) {
        COROUTINE_YIELD();
    }

    //念のために最初に超音波を止める
    digitalWrite(this->trig_pin_, LOW);
    delayMicroseconds(2);
    digitalWrite(this->trig_pin_, HIGH);
    delayMicroseconds(10);
    digitalWrite(this->trig_pin_, LOW);

    //帰ってくるまでの時間を計測
    duration = pulseIn(this->echo_pin_, HIGH);
    duration /= 2;

    //距離の計算
    this->raw_value_ = (double) duration * 340.0 / 10000.0;

    this->last_updated_time_ = millis();
    COROUTINE_END();
}

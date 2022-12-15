#include "sonic_sensor.h"
#include <Arduino.h>

SonicSensor::SonicSensor(int trig_pin, int echo_pin){
    this->trig_pin_ = trig_pin;
    this->echo_pin_ = echo_pin;
    pinMode(this->trig_pin_, OUTPUT);
    pinMode(this->echo_pin_, INPUT);
}

int SonicSensor::Update(){
    COROUTINE_LOOP(){
        //念のために最初に超音波を止める
        digitalWrite(this->trig_pin_, LOW);
        digitalWrite(this->trig_pin_, HIGH);
        COROUTINE_DELAY(10);
        digitalWrite(this->trig_pin_, LOW);
        
        //帰ってくるまでの時間を計測
        unsigned long duration = pulseIn(this->echo_pin_, HIGH);
        duration /= 2;

        //距離の計算
        this->raw_value_ = duration * 340 * 10000;
    }
}

//センサーの現在の値を取得
float SonicSensor::GetRawValue(){
    return this->raw_value_;
}

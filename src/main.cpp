#include <Arduino.h>
#include "sensor.h"
#include "motor.h"

// 車の各コンポーネント
Motor *left_motor;
Motor *right_motor;
Sensor *left_sensor;
Sensor *mid_sensor;
Sensor *right_sensor;

// loopのdelay値
unsigned long delayMillis;

// センサー更新
void updateSensors();
// ライントレース制御
void runLineTraceControl();

void setup() {
    left_motor = new Motor(4, 5, 11);
    right_motor= new Motor(2, 3, 10);
    right_sensor = new Sensor(A0);
    mid_sensor = new Sensor(A1);
    left_sensor = new Sensor(A2);

    delayMillis = 10;

    nomal_power = 100;
    low_power = 120;
    high_power = 150;
}

void loop() {
    updateSensors();
    runLineTraceControl();
    delay(delayMillis);
}

void updateSensors() {
    left_sensor->Update();
    mid_sensor->Update();
    right_sensor->Update();
}

void runLineTraceControl() {
    /* TODO: ライントレース制御アルゴリズムを作る
     * ここでやっていいこと:
     *  - モータの回転数制御
     *  - センサー値の参照
     *  */
    delta = 100;
    //閾値

    int left_value = left_sensor->GetRawValue();
    int mid_value = mid_sensor->GetRawValue();
    int right_value = right_sensor->GetRawValue();
    //センサーの値

    if(left_value < delta || right_value > delta){
        if(mid_value < delta){
            left_motor->UpdateSpeed(high_power);
            right_motor->UpdateSpeed(nomal_power);
        }else{
            left_motor->UpdateSpeed(low_power);
            right_motor->UpdateSpeed(nomal_power);
        }
        //左が白、右が黒のとき
    }else if(left_value > delta || right_value < delta){
         if(mid_value < delta){
            left_motor->UpdateSpeed(nomal_power);
            right_motor->UpdateSpeed(high_power);
        }else{
            left_motor->UpdateSpeed(nomal_power);
            right_motor->UpdateSpeed(low_power);
        }
        //左が黒、右が白のとき
    }else if(left_value < delta || right_value < delta){
        left_motor->UpdateSpeed(nomal_power);
        right_motor->UpdateSpeed(nomal_power);
        //左右どちらも白のとき
    }else{
        left_motor->UpdateSpeed(low_power);
        right_motor->UpdateSpeed(nomal_power);
        //それ以外は左回転
    }

}

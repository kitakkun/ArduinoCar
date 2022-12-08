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
}

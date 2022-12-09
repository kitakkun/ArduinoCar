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

    int left_value;
    int mid_value;
    int right_value;
    int left_F;
    int mid_F;
    int right_F;
    int speed = 100; // 標準の速さ
    int dec = 30; // カーブ時の減速量

    // センサー値の取得
    left_value = left_sensor->GetRawValue();
    mid_value = mid_sensor->GetRawValue();
    right_value = right_sensor->GetRawValue();

    // 各センサーフラグを決定
    left_F = IsBlack(left_value);
    mid_F = IsBlack(mid_value);
    right_F = IsBlack(right_value);

    // 全部白の場合，停止する
    // TODO:即停止ではなく過去のセンサー値を参照したい
    if (left_F && (mid_value < num) && (right_value < num)) {
        left_motor->UpdateSpeed(0);
        right_motor->UpdateSpeed(0);
    }

    // 白黒白の場合，前進する
    if ((left_value < num) && (mid_value >= num) && (right_value < num)) {
        left_motor->UpdateSpeed(speed);
        right_motor->UpdateSpeed(speed);
    }

    // 白白黒の場合，右に曲がる(右車輪の速さを落とす)
    if ((left_value < num) && (mid_value < num) && (right_value >= num)) {
        right_motor->UpdateSpeed(speed - dec);
    }

    // 黒白白の場合，左に曲がる()


}

int IsBlack(int value) {
    int num = 400; // 閾値(num未満なら白，num以上なら黒とする)

    // 黒の場合1を返し，白の場合0を返す
    if (value < num) {
        return 0;
    } else {
        return 1;
    }
}

#include "unity.h"
#include "ArduinoLog.h"
#include "fake.h"
#include "core.h"
#include "custom.h"
#include <Arduino.h>

#define WHITE_VAL 0
#define BLACK_VAL 1000
#define BASE_SPEED 120
#define BACKWARD_TORQUE 10
#define FORWARD_TORQUE 20

Car *car;
FakePhotoReflector *front_mid;
FakePhotoReflector *front_left;
FakePhotoReflector *front_right;
FakePhotoReflector *back_mid;
FakePhotoReflector *back_left;
FakePhotoReflector *back_right;
LineTraceBrain *brain;
Wheel *left_wheel;
Wheel *right_wheel;

void run_life_cycle() {
    car->UpdateSensors();
    car->Think();
    car->Act();
}

void set_all_sensor(int value) {
    front_mid->SetRawValue(value);
    front_right->SetRawValue(value);
    front_left->SetRawValue(value);
    back_mid->SetRawValue(value);
    back_right->SetRawValue(value);
    back_left->SetRawValue(value);
}

void run_ready_test() {
    TEST_ASSERT_EQUAL(ready, brain->ActivityState());
    run_life_cycle();
    TEST_ASSERT_EQUAL(searching, brain->ActivityState());
}

void run_search_test() {
    TEST_ASSERT_EQUAL(searching, brain->ActivityState());
    // 10回分ライフサイクルまわして状態遷移していないことを確認
    for (int i = 0; i < 10; i++) {
        run_life_cycle();
    }
    TEST_ASSERT_EQUAL(searching, brain->ActivityState());
    // 後ろのセンサーを変えても状態遷移しないことを確認
    back_mid->SetRawValue(BLACK_VAL);
    run_life_cycle();
    TEST_ASSERT_EQUAL(searching, brain->ActivityState());
    // 前のセンサーを変えたら状態遷移することを確認
    front_mid->SetRawValue(BLACK_VAL);
    run_life_cycle();
    TEST_ASSERT_EQUAL(0, left_wheel->Speed());
    TEST_ASSERT_EQUAL(0, right_wheel->Speed());
    TEST_ASSERT_EQUAL(tracing, brain->ActivityState());
}

void run_trace_test() {
    TEST_ASSERT_EQUAL(tracing, brain->ActivityState());
    // 発進チェック
    set_all_sensor(WHITE_VAL);
    front_mid->SetRawValue(BLACK_VAL);
    run_life_cycle();
    TEST_ASSERT_EQUAL(BASE_SPEED, left_wheel->Speed());
    TEST_ASSERT_EQUAL(BASE_SPEED, right_wheel->Speed());
    // 前面センサーのテスト ===============================================
    // 直進することを確認
    set_all_sensor(WHITE_VAL);
    front_mid->SetRawValue(BLACK_VAL);
    run_life_cycle();
    TEST_ASSERT_EQUAL(BASE_SPEED, left_wheel->Speed());
    TEST_ASSERT_EQUAL(BASE_SPEED, right_wheel->Speed());
    // 左に曲がることを確認
    set_all_sensor(WHITE_VAL);
    front_left->SetRawValue(BLACK_VAL);
    run_life_cycle();
    TEST_ASSERT_EQUAL(BASE_SPEED - FORWARD_TORQUE, left_wheel->Speed());
    TEST_ASSERT_EQUAL(right_wheel->Speed(), BASE_SPEED);
    // 右に曲がることを確認
    set_all_sensor(WHITE_VAL);
    front_right->SetRawValue(BLACK_VAL);
    run_life_cycle();
    TEST_ASSERT_EQUAL(BASE_SPEED - FORWARD_TORQUE, right_wheel->Speed());
    TEST_ASSERT_EQUAL(left_wheel->Speed(), BASE_SPEED);
    // 背面センサーのテスト ===============================================
    // 直進することを確認
    set_all_sensor(WHITE_VAL);
    back_mid->SetRawValue(BLACK_VAL);
    run_life_cycle();
    TEST_ASSERT_EQUAL(BASE_SPEED, left_wheel->Speed());
    TEST_ASSERT_EQUAL(BASE_SPEED, right_wheel->Speed());
    // 左に曲がることを確認
    set_all_sensor(WHITE_VAL);
    back_left->SetRawValue(BLACK_VAL);
    run_life_cycle();
    TEST_ASSERT_EQUAL(BASE_SPEED - FORWARD_TORQUE, left_wheel->Speed());
    TEST_ASSERT_EQUAL(right_wheel->Speed(), BASE_SPEED);
    // 右に曲がることを確認
    set_all_sensor(WHITE_VAL);
    back_right->SetRawValue(BLACK_VAL);
    run_life_cycle();
    TEST_ASSERT_EQUAL(BASE_SPEED - FORWARD_TORQUE, right_wheel->Speed());
    TEST_ASSERT_EQUAL(left_wheel->Speed(), BASE_SPEED);
    // 全部白にしても状態遷移しない
    TEST_ASSERT_EQUAL(tracing, brain->ActivityState());
    set_all_sensor(WHITE_VAL);
    run_life_cycle();
    TEST_ASSERT_EQUAL(tracing, brain->ActivityState());
}

void run_tests() {
    UNITY_BEGIN();
    RUN_TEST(run_ready_test);
    RUN_TEST(run_search_test);
    RUN_TEST(run_trace_test);
    UNITY_END();
}

void setup() {
    Serial.begin(115200);
    while (!Serial);
    Log.begin(LOG_LEVEL_VERBOSE, &Serial, true);
    Log.verboseln("Building a Car instance...");

    front_mid = new FakePhotoReflector(500);
    front_left = new FakePhotoReflector(500);
    front_right = new FakePhotoReflector(500);
    back_mid = new FakePhotoReflector(500);
    back_left = new FakePhotoReflector(500);
    back_right = new FakePhotoReflector(500);
    brain = new LineTraceContinuousBrain(BASE_SPEED, FORWARD_TORQUE);
    left_wheel = new FakeWheel();
    right_wheel = new FakeWheel();

    LineTraceCarBuilder builder = LineTraceCarBuilder();
    builder.SetBrain(brain);
    builder.SetLeftWheel(left_wheel);
    builder.SetRightWheel(right_wheel);
    builder.SetFrontMidReflector(front_mid);
    builder.SetFrontRightReflector(front_right);
    builder.SetFrontLeftReflector(front_left);
    builder.SetBackMidReflector(back_mid);
    builder.SetBackRightReflector(back_right);
    builder.SetBackLeftReflector(back_left);
    car = builder.Build();

    // 全部白にしておく
    front_mid->SetRawValue(0);
    front_left->SetRawValue(0);
    front_right->SetRawValue(0);
    back_mid->SetRawValue(0);
    back_left->SetRawValue(0);
    back_right->SetRawValue(0);

    Log.verboseln("Done! Start Testing.");

    delay(1000);

    UNITY_BEGIN();
    run_tests();
    UNITY_END();
}

void loop() {}

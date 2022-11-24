#include "unity.h"
#include "ArduinoLog.h"
#include "fake.h"
#include "core.h"
#include "custom.h"
#include <Arduino.h>

const int white_val = 0;
const int black_val = 1000;
const int base_speed = 120;
const int forward_torque = 20;
const int backward_torque = 10;

Car *car;
FakePhotoReflector *mid;
FakePhotoReflector *left;
FakePhotoReflector *right;
LineTraceBrain *brain;
Wheel *left_wheel;
Wheel *right_wheel;

void run_life_cycle() {
    car->UpdateSensors();
    car->Think();
    car->Act();
}

void set_all_sensor(int value) {
    mid->SetRawValue(value);
    right->SetRawValue(value);
    left->SetRawValue(value);
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
    // 前のセンサーを変えたら状態遷移することを確認
    mid->SetRawValue(black_val);
    run_life_cycle();
    TEST_ASSERT_EQUAL(0, left_wheel->Speed());
    TEST_ASSERT_EQUAL(0, right_wheel->Speed());
    TEST_ASSERT_EQUAL(tracing, brain->ActivityState());
}

void run_trace_test() {
    TEST_ASSERT_EQUAL(tracing, brain->ActivityState());
    // 発進チェック
    set_all_sensor(white_val);
    mid->SetRawValue(black_val);
    run_life_cycle();
    TEST_ASSERT_EQUAL(base_speed, left_wheel->Speed());
    TEST_ASSERT_EQUAL(base_speed, right_wheel->Speed());
    // 前面センサーのテスト ===============================================
    // 直進することを確認
    set_all_sensor(white_val);
    mid->SetRawValue(black_val);
    run_life_cycle();
    TEST_ASSERT_EQUAL(base_speed, left_wheel->Speed());
    TEST_ASSERT_EQUAL(base_speed, right_wheel->Speed());
    // 左に曲がることを確認
    set_all_sensor(white_val);
    left->SetRawValue(black_val);
    run_life_cycle();
    TEST_ASSERT_EQUAL(base_speed - forward_torque, left_wheel->Speed());
    TEST_ASSERT_EQUAL(right_wheel->Speed(), base_speed);
    // 右に曲がることを確認
    set_all_sensor(white_val);
    right->SetRawValue(black_val);
    run_life_cycle();
    TEST_ASSERT_EQUAL(base_speed - forward_torque, right_wheel->Speed());
    TEST_ASSERT_EQUAL(left_wheel->Speed(), base_speed);
    // 全部白にして状態遷移
    TEST_ASSERT_EQUAL(tracing, brain->ActivityState());
    set_all_sensor(white_val);
    run_life_cycle();
    TEST_ASSERT_EQUAL(readyBack, brain->ActivityState());
}

void run_readyBack_test() {
    TEST_ASSERT_EQUAL(readyBack, brain->ActivityState());
    // 方向転換して次の状態に遷移していることをテスト
    run_life_cycle();
    TEST_ASSERT_EQUAL(backward, left_wheel->Direction());
    TEST_ASSERT_EQUAL(backward, right_wheel->Direction());
    TEST_ASSERT_EQUAL(searchingBack, brain->ActivityState());
}

void run_searchingBack_test() {
    TEST_ASSERT_EQUAL(searchingBack, brain->ActivityState());
    set_all_sensor(white_val);
    // 10回分ライフサイクルまわして状態遷移していないことを確認
    for (int i = 0; i < 10; i++) {
        run_life_cycle();
    }
    TEST_ASSERT_EQUAL(searchingBack, brain->ActivityState());
    // 前のセンサーを変えたら状態遷移することを確認
    mid->SetRawValue(black_val);
    run_life_cycle();
    TEST_ASSERT_EQUAL(0, left_wheel->Speed());
    TEST_ASSERT_EQUAL(0, right_wheel->Speed());
    TEST_ASSERT_EQUAL(tracingBack, brain->ActivityState());
}

void run_traceBack_test() {
    TEST_ASSERT_EQUAL(tracingBack, brain->ActivityState());
    // 発進
    run_life_cycle();
    TEST_ASSERT_EQUAL(base_speed, left_wheel->Speed());
    TEST_ASSERT_EQUAL(base_speed, right_wheel->Speed());
    // 前面センサーのテスト ===============================================
    // 直進することを確認
    set_all_sensor(white_val);
    mid->SetRawValue(black_val);
    run_life_cycle();
    TEST_ASSERT_EQUAL(base_speed, left_wheel->Speed());
    TEST_ASSERT_EQUAL(base_speed, right_wheel->Speed());
    // 右に曲がることを確認
    set_all_sensor(white_val);
    left->SetRawValue(black_val);
    run_life_cycle();
    TEST_ASSERT_EQUAL(base_speed - backward_torque, left_wheel->Speed());
    TEST_ASSERT_EQUAL(right_wheel->Speed(), base_speed);
    // 左に曲がることを確認
    set_all_sensor(white_val);
    right->SetRawValue(black_val);
    run_life_cycle();
    TEST_ASSERT_EQUAL(base_speed - backward_torque, right_wheel->Speed());
    TEST_ASSERT_EQUAL(left_wheel->Speed(), base_speed);
    // 全部白にして状態遷移
    TEST_ASSERT_EQUAL(tracingBack, brain->ActivityState());
    set_all_sensor(white_val);
    run_life_cycle();
    TEST_ASSERT_EQUAL(finished, brain->ActivityState());
}

void run_finish_test() {
    TEST_ASSERT_EQUAL(finished, brain->ActivityState());
    // 停止していることを確認
    for (int i = 0; i < 10; i++) {
        run_life_cycle();
        TEST_ASSERT_EQUAL(0, left_wheel->Speed());
        TEST_ASSERT_EQUAL(0, right_wheel->Speed());
    }
}

void run_tests() {
    UNITY_BEGIN();
    RUN_TEST(run_ready_test);
    RUN_TEST(run_search_test);
    RUN_TEST(run_trace_test);
    RUN_TEST(run_readyBack_test);
    RUN_TEST(run_searchingBack_test);
    RUN_TEST(run_traceBack_test);
    UNITY_END();
}

void setup() {
    Serial.begin(115200);
    while (!Serial);
    Log.begin(LOG_LEVEL_VERBOSE, &Serial, true);
    Log.verboseln("Building a Car instance...");

    brain = new LineTraceGoAndBackBrain(base_speed, forward_torque, backward_torque);
    left_wheel = new FakeWheel();
    right_wheel = new FakeWheel();
    mid = new FakePhotoReflector(500);
    left = new FakePhotoReflector(500);
    right = new FakePhotoReflector(500);

    car = LineTraceCarBuilder()
            .SetBrain(brain)
            .SetLeftWheel(left_wheel)
            .SetRightWheel(right_wheel)
            .SetMidReflector(mid)
            .SetRightReflector(right)
            .SetLeftReflector(left)
            .Build();

    // 全部白にしておく
    mid->SetRawValue(0);
    left->SetRawValue(0);
    right->SetRawValue(0);

    Log.verboseln("Done! Start Testing.");

    delay(1000);

    UNITY_BEGIN();
    run_tests();
    UNITY_END();
}

void loop() {}

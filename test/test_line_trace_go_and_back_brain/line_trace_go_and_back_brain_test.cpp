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
    back_mid->SetRawValue(black_val);
    run_life_cycle();
    TEST_ASSERT_EQUAL(searching, brain->ActivityState());
    // 前のセンサーを変えたら状態遷移することを確認
    front_mid->SetRawValue(black_val);
    run_life_cycle();
    TEST_ASSERT_EQUAL(0, left_wheel->Speed());
    TEST_ASSERT_EQUAL(0, right_wheel->Speed());
    TEST_ASSERT_EQUAL(tracing, brain->ActivityState());
}

void run_trace_test() {
    TEST_ASSERT_EQUAL(tracing, brain->ActivityState());
    // 発進チェック
    set_all_sensor(white_val);
    front_mid->SetRawValue(black_val);
    run_life_cycle();
    TEST_ASSERT_EQUAL(base_speed, left_wheel->Speed());
    TEST_ASSERT_EQUAL(base_speed, right_wheel->Speed());
    // 前面センサーのテスト ===============================================
    // 直進することを確認
    set_all_sensor(white_val);
    front_mid->SetRawValue(black_val);
    run_life_cycle();
    TEST_ASSERT_EQUAL(base_speed, left_wheel->Speed());
    TEST_ASSERT_EQUAL(base_speed, right_wheel->Speed());
    // 左に曲がることを確認
    set_all_sensor(white_val);
    front_left->SetRawValue(black_val);
    run_life_cycle();
    TEST_ASSERT_EQUAL(base_speed - forward_torque, left_wheel->Speed());
    TEST_ASSERT_EQUAL(right_wheel->Speed(), base_speed);
    // 右に曲がることを確認
    set_all_sensor(white_val);
    front_right->SetRawValue(black_val);
    run_life_cycle();
    TEST_ASSERT_EQUAL(base_speed - forward_torque, right_wheel->Speed());
    TEST_ASSERT_EQUAL(left_wheel->Speed(), base_speed);
    // 背面センサーのテスト ===============================================
    // 直進することを確認
    set_all_sensor(white_val);
    back_mid->SetRawValue(black_val);
    run_life_cycle();
    TEST_ASSERT_EQUAL(base_speed, left_wheel->Speed());
    TEST_ASSERT_EQUAL(base_speed, right_wheel->Speed());
    // 左に曲がることを確認
    set_all_sensor(white_val);
    back_left->SetRawValue(black_val);
    run_life_cycle();
    TEST_ASSERT_EQUAL(base_speed - forward_torque, left_wheel->Speed());
    TEST_ASSERT_EQUAL(right_wheel->Speed(), base_speed);
    // 右に曲がることを確認
    set_all_sensor(white_val);
    back_right->SetRawValue(black_val);
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
    // 前のセンサーを変えても状態遷移しないことを確認
    front_mid->SetRawValue(black_val);
    run_life_cycle();
    TEST_ASSERT_EQUAL(searchingBack, brain->ActivityState());
    // 後ろのセンサーを変えたら状態遷移することを確認
    back_mid->SetRawValue(black_val);
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
    // 背面センサーのテスト ===============================================
    // 直進することを確認
    set_all_sensor(white_val);
    back_mid->SetRawValue(black_val);
    run_life_cycle();
    TEST_ASSERT_EQUAL(base_speed, left_wheel->Speed());
    TEST_ASSERT_EQUAL(base_speed, right_wheel->Speed());
    // 右に曲がることを確認
    set_all_sensor(white_val);
    back_left->SetRawValue(black_val);
    run_life_cycle();
    TEST_ASSERT_EQUAL(base_speed - backward_torque, left_wheel->Speed());
    TEST_ASSERT_EQUAL(right_wheel->Speed(), base_speed);
    // 左に曲がることを確認
    set_all_sensor(white_val);
    back_right->SetRawValue(black_val);
    run_life_cycle();
    TEST_ASSERT_EQUAL(base_speed - backward_torque, right_wheel->Speed());
    TEST_ASSERT_EQUAL(left_wheel->Speed(), base_speed);
    // 前面センサーのテスト ===============================================
    // 直進することを確認
    set_all_sensor(white_val);
    front_mid->SetRawValue(black_val);
    run_life_cycle();
    TEST_ASSERT_EQUAL(base_speed, left_wheel->Speed());
    TEST_ASSERT_EQUAL(base_speed, right_wheel->Speed());
    // 右に曲がることを確認
    set_all_sensor(white_val);
    front_left->SetRawValue(black_val);
    run_life_cycle();
    TEST_ASSERT_EQUAL(base_speed - backward_torque, left_wheel->Speed());
    TEST_ASSERT_EQUAL(right_wheel->Speed(), base_speed);
    // 左に曲がることを確認
    set_all_sensor(white_val);
    front_right->SetRawValue(black_val);
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
    front_mid = new FakePhotoReflector(500);
    front_left = new FakePhotoReflector(500);
    front_right = new FakePhotoReflector(500);
    back_mid = new FakePhotoReflector(500);
    back_left = new FakePhotoReflector(500);
    back_right = new FakePhotoReflector(500);

    car = LineTraceCarBuilder()
            .SetBrain(brain)
            .SetLeftWheel(left_wheel)
            .SetRightWheel(right_wheel)
            .SetMidReflector(front_mid)
            .SetMidReflector(front_right)
            .SetMidReflector(front_left)
            .SetMidReflector(back_mid)
            .SetMidReflector(back_right)
            .SetMidReflector(back_left)
            .Build();

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

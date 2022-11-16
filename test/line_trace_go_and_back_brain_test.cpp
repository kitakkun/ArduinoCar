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
FakePhotoReflector *front_mid = new FakePhotoReflector(500);
FakePhotoReflector *front_left = new FakePhotoReflector(500);
FakePhotoReflector *front_right = new FakePhotoReflector(500);
FakePhotoReflector *back_mid = new FakePhotoReflector(500);
FakePhotoReflector *back_left = new FakePhotoReflector(500);
FakePhotoReflector *back_right = new FakePhotoReflector(500);
LineTraceBrain *brain;
Wheel *left_wheel;
Wheel *right_wheel;

void run_life_cycle() {
    car->UpdateSensors();
    car->Think();
    car->Act();
}

// readyからsearchingへの遷移テスト
void run_ready_to_search_test() {
    TEST_ASSERT_EQUAL(ready, brain->ActivityState());
    run_life_cycle();
    TEST_ASSERT_EQUAL(searching, brain->ActivityState());
}

// searchingからtracingへの遷移テスト
void run_search_to_trace_test() {
    TEST_ASSERT_EQUAL(searching, brain->ActivityState());
    run_life_cycle();
    TEST_ASSERT_EQUAL(searching, brain->ActivityState());
    back_mid->SetRawValue(BLACK_VAL);
    run_life_cycle();
    TEST_ASSERT_EQUAL(searching, brain->ActivityState());
    back_mid->SetRawValue(WHITE_VAL);
    front_mid->SetRawValue(BLACK_VAL);
    run_life_cycle();
    TEST_ASSERT_EQUAL(tracing, brain->ActivityState());
}

void run_trace_torque_test() {
    TEST_ASSERT_EQUAL(tracing, brain->ActivityState());
    run_life_cycle();
    front_left->SetRawValue(BLACK_VAL);
    run_life_cycle();
    TEST_ASSERT_EQUAL(BASE_SPEED - FORWARD_TORQUE, left_wheel->Speed());
    TEST_ASSERT_EQUAL(right_wheel->Speed(), BASE_SPEED);
    run_life_cycle();
    TEST_ASSERT_EQUAL(BASE_SPEED - FORWARD_TORQUE, left_wheel->Speed());
    TEST_ASSERT_EQUAL(right_wheel->Speed(), BASE_SPEED);
    front_left->SetRawValue(WHITE_VAL);
    front_right->SetRawValue(BLACK_VAL);
    run_life_cycle();
    TEST_ASSERT_EQUAL(BASE_SPEED - FORWARD_TORQUE, right_wheel->Speed());
    TEST_ASSERT_EQUAL(left_wheel->Speed(), BASE_SPEED);
}

void run_trace_move_forward_test() {
    TEST_ASSERT_EQUAL(tracing, brain->ActivityState());
    front_left->SetRawValue(WHITE_VAL);
    front_right->SetRawValue(WHITE_VAL);
    delay(500);
    run_life_cycle();
    TEST_ASSERT_EQUAL(BASE_SPEED, left_wheel->Speed());
    TEST_ASSERT_EQUAL(BASE_SPEED, right_wheel->Speed());
}

void run_trace_to_ready_back_test() {
    TEST_ASSERT_EQUAL(tracing, brain->ActivityState());
    front_left->SetRawValue(WHITE_VAL);
    front_right->SetRawValue(WHITE_VAL);
    front_mid->SetRawValue(WHITE_VAL);
    back_left->SetRawValue(WHITE_VAL);
    back_right->SetRawValue(WHITE_VAL);
    back_mid->SetRawValue(WHITE_VAL);
    run_life_cycle();
    TEST_ASSERT_EQUAL(tracing, brain->ActivityState());
    delay(2000);
    run_life_cycle();
    TEST_ASSERT_EQUAL(readyBack, brain->ActivityState());
}

void run_ready_back_to_searching_back_test() {
    TEST_ASSERT_EQUAL(readyBack, brain->ActivityState());
    run_life_cycle();
    TEST_ASSERT_EQUAL(backward, left_wheel->Direction());
    TEST_ASSERT_EQUAL(backward, right_wheel->Direction());
    TEST_ASSERT_EQUAL(searchingBack, brain->ActivityState());
}

void run_searching_back_to_tracing_back_test() {
    run_life_cycle();
    TEST_ASSERT_EQUAL(BASE_SPEED, left_wheel->Speed());
    TEST_ASSERT_EQUAL(BASE_SPEED, right_wheel->Speed());
    TEST_ASSERT_EQUAL(searchingBack, brain->ActivityState());
    run_life_cycle();
    back_mid->SetRawValue(BLACK_VAL);
    run_life_cycle();
    TEST_ASSERT_EQUAL(0, left_wheel->Speed());
    TEST_ASSERT_EQUAL(0, right_wheel->Speed());
    TEST_ASSERT_EQUAL(tracingBack, brain->ActivityState());
}

void run_trace_back_torque_test() {
    TEST_ASSERT_EQUAL(tracingBack, brain->ActivityState());
    run_life_cycle();
    TEST_ASSERT_EQUAL(BASE_SPEED, left_wheel->Speed());
    TEST_ASSERT_EQUAL(BASE_SPEED, right_wheel->Speed());
    // 左に曲がる
    back_right->SetRawValue(BLACK_VAL);
    run_life_cycle();
    TEST_ASSERT_EQUAL(BASE_SPEED - BACKWARD_TORQUE, right_wheel->Speed());
    TEST_ASSERT_EQUAL(BASE_SPEED, left_wheel->Speed());
    // 右に曲がる
    back_right->SetRawValue(WHITE_VAL);
    back_left->SetRawValue(BLACK_VAL);
    run_life_cycle();
    TEST_ASSERT_EQUAL(BASE_SPEED - BACKWARD_TORQUE, left_wheel->Speed());
    TEST_ASSERT_EQUAL(BASE_SPEED, right_wheel->Speed());
    run_life_cycle();
}

void run_trace_back_move_forward_test() {
    TEST_ASSERT_EQUAL(tracingBack, brain->ActivityState());
    back_mid->SetRawValue(BLACK_VAL);
    back_left->SetRawValue(WHITE_VAL);
    back_right->SetRawValue(WHITE_VAL);
    run_life_cycle();
    TEST_ASSERT_EQUAL(BASE_SPEED, left_wheel->Speed());
    TEST_ASSERT_EQUAL(BASE_SPEED, right_wheel->Speed());
    TEST_ASSERT_EQUAL(backward, left_wheel->Direction());
    TEST_ASSERT_EQUAL(backward, right_wheel->Direction());
}

void run_trace_back_to_finish_test() {
    TEST_ASSERT_EQUAL(tracingBack, brain->ActivityState());
    back_mid->SetRawValue(WHITE_VAL);
    back_left->SetRawValue(WHITE_VAL);
    back_right->SetRawValue(WHITE_VAL);
    run_life_cycle();
    delay(1000);
    run_life_cycle();
    TEST_ASSERT_EQUAL(finished, brain->ActivityState());
}

void run_tests() {
    UNITY_BEGIN();
    RUN_TEST(run_ready_to_search_test);
    RUN_TEST(run_search_to_trace_test);
    RUN_TEST(run_trace_torque_test);
    RUN_TEST(run_trace_move_forward_test);
    RUN_TEST(run_trace_to_ready_back_test);
    RUN_TEST(run_ready_back_to_searching_back_test);
    RUN_TEST(run_searching_back_to_tracing_back_test);
    RUN_TEST(run_trace_back_torque_test);
    RUN_TEST(run_trace_back_move_forward_test);
    RUN_TEST(run_trace_back_to_finish_test);
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
    brain = new LineTraceGoAndBackBrain(BASE_SPEED, FORWARD_TORQUE, BACKWARD_TORQUE);
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

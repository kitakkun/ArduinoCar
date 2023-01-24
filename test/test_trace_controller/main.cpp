#include <Arduino.h>
#include "unity.h"
#include "controller/trace/pid_trace_controller.h"
#include "fake.h"

void runUnityTests();

CarController *controller;
TraceCar *car;
FakeMotor *left_motor;
FakeMotor *right_motor;
FakeReflector *mid_reflector;
FakeReflector *left_reflector;
FakeReflector *right_reflector;

void setup() {

    int theta = 500;

    left_motor = new FakeMotor();
    right_motor = new FakeMotor();
    mid_reflector = new FakeReflector(theta);
    left_reflector = new FakeReflector(theta);
    right_reflector = new FakeReflector(theta);

    car = new TraceCar(
            left_motor,
            right_motor,
            mid_reflector,
            left_reflector,
            right_reflector
    );
    controller = new PidTraceController(
            car,
            100,
            0,
            80,
            0.5,
            0.2
    );

    delay(1000);
    runUnityTests();
}

void runLifecycle() {
    controller->Update();
    controller->Operate();
    delay(10);
}

void reset() {
    left_motor->UpdateSpeed(0);
    right_motor->UpdateSpeed(0);
    right_reflector->SetRawValue(0);
    left_reflector->SetRawValue(0);
    runLifecycle();
    runLifecycle();
    runLifecycle();
}

/* 左右のセンサー値が同じ状態では速度調整が発生しないことをチェック */
void noSpeedChangeTest() {
    int test_cases[][2] = {
            {0,   0},
            {100, 100},
            {50,  50},
            {20,  20},
    };
    for (int *test_case: test_cases) {
        left_reflector->SetRawValue(test_case[0]);
        right_reflector->SetRawValue(test_case[1]);
        runLifecycle();
        TEST_ASSERT_EQUAL(left_motor->GetSpeed(), right_motor->GetSpeed());
    }
}

/* P制御で左に曲がろうとするかのテスト
 * 左の方がセンサー値が大きい想定 */
void pTorqueLeftTest() {
    int test_cases[][2] = {
            {10,  0},
            {120, 100},
            {80,  50},
            {90,  20},
    };
    for (int *test_case: test_cases) {
        left_reflector->SetRawValue(test_case[0]);
        right_reflector->SetRawValue(test_case[1]);
        runLifecycle();
        TEST_ASSERT_GREATER_THAN(left_motor->GetSpeed(), right_motor->GetSpeed());
        left_reflector->SetRawValue(0);
        right_reflector->SetRawValue(0);
        runLifecycle();
        runLifecycle();
        runLifecycle();
    }
}

/* P制御で右に曲がろうとするかのテスト
 * 右の方がセンサー値が大きい想定 */
void pTorqueRightTest() {
    int test_cases[][2] = {
            {0,   10},
            {100, 120},
            {50,  80},
            {20,  90},
    };
    for (int *test_case: test_cases) {
        left_reflector->SetRawValue(test_case[0]);
        right_reflector->SetRawValue(test_case[1]);
        runLifecycle();
        TEST_ASSERT_GREATER_THAN(right_motor->GetSpeed(), left_motor->GetSpeed());
        left_reflector->SetRawValue(0);
        right_reflector->SetRawValue(0);
        runLifecycle();
        runLifecycle();
        runLifecycle();
    }
}

/* D制御がちゃんと働いているかのテスト
 * 変化量が急激なときとそうでないときの速度変化を比較 */
void dTorqueLeftTest() {
    // いきなり左が巨大(100)になる
    reset();
    left_reflector->SetRawValue(100);
    right_reflector->SetRawValue(0);
    runLifecycle();
    int lr_diff_high = right_motor->GetSpeed() - left_motor->GetSpeed();
    // 500の状態を経由して1000になる
    reset();
    left_reflector->SetRawValue(50);
    right_reflector->SetRawValue(0);
    runLifecycle();
    left_reflector->SetRawValue(100);
    right_reflector->SetRawValue(0);
    runLifecycle();
    int lr_diff_low = right_motor->GetSpeed() - left_motor->GetSpeed();
    TEST_ASSERT_GREATER_THAN(lr_diff_low, lr_diff_high);
}

/* D制御がちゃんと働いているかのテスト
 * 変化量が急激なときとそうでないときの速度変化を比較 */
void dTorqueRightTest() {
    // いきなり右が巨大(1000)になる
    reset();
    left_reflector->SetRawValue(0);
    right_reflector->SetRawValue(100);
    runLifecycle();
    int lr_diff_high = left_motor->GetSpeed() - right_motor->GetSpeed();
    // 500の状態を経由して1000になる
    reset();
    left_reflector->SetRawValue(0);
    right_reflector->SetRawValue(50);
    runLifecycle();
    left_reflector->SetRawValue(0);
    right_reflector->SetRawValue(100);
    runLifecycle();
    int lr_diff_low = left_motor->GetSpeed() - right_motor->GetSpeed();
    TEST_ASSERT_GREATER_THAN(lr_diff_low, lr_diff_high);
}

void runUnityTests() {
    UNITY_BEGIN();
    RUN_TEST(noSpeedChangeTest);
    RUN_TEST(pTorqueLeftTest);
    RUN_TEST(pTorqueRightTest);
    RUN_TEST(dTorqueLeftTest);
    RUN_TEST(dTorqueRightTest);
    UNITY_END();
}

void loop() {}

#include "unity.h"
#include <Arduino.h>
#include <ArduinoSTL.h>

std::vector<int> pins = {A0, A1, A2, A3, A4, A5};
std::vector<int> values(6);

void tearDown() {
    // clean stuff up here
}

// 黒が検出できているかのテスト
void test_black_detection() {
    std::cout << "Black Detection Test starts in 5 seconds. Please place sensors on black area." << std::endl;
    for (int i = 0; i < 5; i++) {
        std::cout << "starts in " << 5 - i << " seconds...";
        std::cout << std::endl;
        delay(1000);
    }
    for (int i = 0; i < pins.size(); i++) {
        int pin = pins[i];
        int value = analogRead(pin);
        values[i] = value;
    }
    for (int i = 0; i < pins.size(); i++) {
        std::cout << "[pin" << i << "] "
                  << "black: " << values[i]
                  << std::endl;
    }
    for (int i = 0; i < pins.size(); i++) {
        TEST_ASSERT_GREATER_OR_EQUAL(500, values[i]);
    }
}

// 白が検出できているかのテスト
void test_white_detection() {
    std::cout << "White Detection Test starts in 5 seconds. Please place sensors on black area." << std::endl;
    for (int i = 0; i < 5; i++) {
        std::cout << "starts in " << 5 - i << " seconds...";
        std::cout << std::endl;
        delay(1000);
    }
    for (int i = 0; i < pins.size(); i++) {
        int pin = pins[i];
        int value = analogRead(pin);
        values[i] = value;
    }
    for (int i = 0; i < pins.size(); i++) {
        std::cout << "[pin" << i << "] "
                  << "white: " << values[i]
                  << std::endl;
    }
    for (int i = 0; i < pins.size(); i++) {
        TEST_ASSERT_LESS_OR_EQUAL(500, values[i]);
    }
}

int runUnityTests() {
    UNITY_BEGIN();
    RUN_TEST(test_black_detection);
    RUN_TEST(test_white_detection);
    return UNITY_END();
}

void setup() {
    // Wait ~2 seconds before the Unity test runner
    // establishes connection with a board Serial interface
    delay(2000);

    runUnityTests();
}
void loop() {}

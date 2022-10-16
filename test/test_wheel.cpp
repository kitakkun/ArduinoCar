#include "unity.h"
#include "component/wheel/wheel.h"

void setup() { }

void teardown() { }

void test_wheel_speed_updates() {
    Wheel *wheel = new Wheel(0, 0, 0);
    wheel->UpdateSpeed(100);
    TEST_ASSERT_EQUAL_INT(100, wheel->Speed());
    wheel->UpdateSpeed(50);
    TEST_ASSERT_EQUAL_INT(50, wheel->Speed());
    delete wheel;
}

void test_wheel_direction_updates() {
    Wheel *wheel = new Wheel(0, 0, 0);
    wheel->UpdateDirection(forward);
    TEST_ASSERT_EQUAL(forward , wheel->Direction());
    wheel->UpdateDirection(backward);
    TEST_ASSERT_EQUAL(backward, wheel->Direction());
    delete wheel;
}

int runUnityTests() {
    UNITY_BEGIN();
    RUN_TEST(test_wheel_speed_updates);
    RUN_TEST(test_wheel_direction_updates);
    return UNITY_END();
}

int main() {
    return runUnityTests();
}
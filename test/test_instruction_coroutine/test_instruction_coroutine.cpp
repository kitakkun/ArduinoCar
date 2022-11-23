#include "unity.h"
#include "core.h"
#include "ArduinoLog.h"

class TestInstruction : public Instruction {
public:
    int Run(Wheel *left_wheel, Wheel *right_wheel) override {
        COROUTINE_BEGIN();
        Log.verboseln("Hello, ");
        COROUTINE_DELAY(1000);
        Log.verboseln("Coroutine");
        COROUTINE_DELAY(2000);
        Log.verboseln("Instruction");
        COROUTINE_END();
    }
};

TestInstruction *instruction;

void run_tests() {
    unsigned long start_time = millis();
    instruction->Run(nullptr, nullptr);
    TEST_ASSERT(!instruction->isDone());
    // 5秒間
    while(millis() - start_time < 5000) {
        instruction->Run(nullptr, nullptr);
    }
    TEST_ASSERT(instruction->isDone());
}

void setup() {
    Serial.begin(115200);
    while (!Serial);
    Log.begin(LOG_LEVEL_VERBOSE, &Serial, true);
    instruction = new TestInstruction();

    UNITY_BEGIN();
    run_tests();
    UNITY_END();
}

void loop() {}
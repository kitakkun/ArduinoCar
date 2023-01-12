#include <Arduino.h>
#include "impl/led/heartbeat_led_impl.h"
#include "unity.h"

/**
 * ハートビートLEDの点滅テスト
 * 1秒間に1回間隔でLEDをオンオフする
 * 10秒間テスト
 */

void setup() {
    HeartbeatLedImpl *heartbeatLed = new HeartbeatLedImpl(13, 1000);
    delay(1000);
    UNITY_BEGIN();
    unsigned long start_time = millis();
    // 5秒間点滅させる
    while (millis() - start_time < 10000) {
        heartbeatLed->runCoroutine();
    }
    UNITY_END();
}

void loop() {}

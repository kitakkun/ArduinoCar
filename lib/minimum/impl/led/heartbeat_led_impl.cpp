#include "heartbeat_led_impl.h"

HeartbeatLedImpl::HeartbeatLedImpl(int pin, int interval_millis) : LedImpl(pin) {
    this->interval_millis_ = interval_millis;
}

int HeartbeatLedImpl::runCoroutine() {
    COROUTINE_LOOP() {
        this->Toggle();
        COROUTINE_DELAY(this->interval_millis_);
    }
}

#ifndef LABORATORY_WORK_IN_INFORMATION_ENGINEERING_III_HEARTBEAT_LED_IMPL_H
#define LABORATORY_WORK_IN_INFORMATION_ENGINEERING_III_HEARTBEAT_LED_IMPL_H

#include "led_impl.h"
#include "ace_routine/Coroutine.h"

class HeartbeatLedImpl : LedImpl, ace_routine::Coroutine {
public:
    explicit HeartbeatLedImpl(int pin, int interval_millis);

    int runCoroutine() override;

private:
    int interval_millis_;
};

#endif //LABORATORY_WORK_IN_INFORMATION_ENGINEERING_III_HEARTBEAT_LED_IMPL_H

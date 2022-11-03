#include "LogCoroutineInstruction.h"
#include "ArduinoLog.h"

int LogCoroutineInstruction::runCoroutine() {
    COROUTINE_BEGIN();
    Log.verboseln("%d", counter);
    counter++;
    COROUTINE_DELAY(1000);
    Log.verboseln("%d", counter);
    counter++;
    COROUTINE_DELAY(1000);
    COROUTINE_COMPLETE();
}

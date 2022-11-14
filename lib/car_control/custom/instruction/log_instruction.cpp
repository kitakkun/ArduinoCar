#include "log_instruction.h"
#include "ArduinoLog.h"

int LogInstruction::runCoroutine() {
    COROUTINE_BEGIN();
    Log.verboseln("TEST");
    COROUTINE_DELAY(1000);
    Log.verboseln("DELAYED");
    COROUTINE_DELAY(1000);
    Log.verboseln("DELAYED AGAIN");
    COROUTINE_END();
}

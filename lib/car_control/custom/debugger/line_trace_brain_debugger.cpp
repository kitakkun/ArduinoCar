#include "line_trace_brain_debugger.h"
#include "ArduinoLog.h"

LineTraceBrainDebugger::LineTraceBrainDebugger(LineTraceBrain *brain) {
    this->brain_ = brain;
}

void LineTraceBrainDebugger::PrintDebugLog() {
    Log.verboseln("[LineTraceBrainDebugger] state = %d", brain_->ActivityState());
}

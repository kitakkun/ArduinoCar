#include "line_trace_brain.h"

LineTraceBrain::LineTraceBrain(String tag) : Debuggable(tag) {
    last_time_called_ = millis();
}

void LineTraceBrain::SetCurrentCarState(LineTraceCarState car_state) {
    current_car_state_ = car_state;
}

Instruction *LineTraceBrain::CalculateNextInstruction() {
    switch (activity_state_) {
        case ready:
            return Ready();
        case searching:
            return Search();
        case tracing:
            return Trace();
        case readyBack:
            return ReadyBack();
        case searchingBack:
            return SearchBack();
        case tracingBack:
            return TraceBack();
        case finished:
        default:
            return Finish();
    }
    last_time_called_ = millis();
}

LineTraceActivityState LineTraceBrain::ActivityState() {
    return activity_state_;
}

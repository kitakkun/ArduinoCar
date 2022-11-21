#include "line_trace_brain.h"

LineTraceBrain::LineTraceBrain(String tag) : Debuggable(tag) {
    last_time_called_ = millis();
}

void LineTraceBrain::SetCurrentCarState(LineTraceCarState car_state) {
    current_car_state_ = car_state;
}

Instruction *LineTraceBrain::CalculateNextInstruction() {
    Instruction *instruction;
    switch (activity_state_) {
        case ready:
            instruction = Ready();
        case searching:
            instruction = Search();
        case tracing:
            instruction = Trace();
        case readyBack:
            instruction = ReadyBack();
        case searchingBack:
            instruction = SearchBack();
        case tracingBack:
            instruction = TraceBack();
        case finished:
        default:
            instruction = Finish();
    }
    last_time_called_ = millis();
    return instruction;
}

LineTraceActivityState LineTraceBrain::ActivityState() {
    return activity_state_;
}

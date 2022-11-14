#include "line_trace_brain.h"
#include "custom/instructions.h"
#include "custom/debug/logger.h"

void LineTraceBrain::SetCurrentCarState(LineTraceCarState car_state) {
    Logger::LogLineTraceCarState(car_state);
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
            return new ForceStopInstruction();
    }
}

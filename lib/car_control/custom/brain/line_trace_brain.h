#ifndef ZIGZAG_LINE_TRACE_BRAIN
#define ZIGZAG_LINE_TRACE_BRAIN

#include "core/logic/brain.h"
#include "custom/data_model/line_trace_car_state.h"

enum LineTraceActivityState {
    ready,
    searching,
    tracing,
    readyBack,
    searchingBack,
    tracingBack,
    finished
};

class LineTraceBrain : public Brain, public Debuggable {
public:
    explicit LineTraceBrain(String tag = "LineTraceBrain");

    void SetCurrentCarState(LineTraceCarState car_state);

    Instruction *CalculateNextInstruction() override;

    LineTraceActivityState ActivityState();

protected:
    virtual Instruction *Ready() = 0;

    virtual Instruction *Search() = 0;

    virtual Instruction *Trace() = 0;

    virtual Instruction *ReadyBack() = 0;

    virtual Instruction *SearchBack() = 0;

    virtual Instruction *TraceBack() = 0;

    virtual Instruction *Finish() = 0;

    LineTraceCarState current_car_state_;
    LineTraceActivityState activity_state_ = ready;
    unsigned long last_time_called_;
};

#endif // ZIGZAG_LINE_TRACE_BRAIN

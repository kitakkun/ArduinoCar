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

class LineTraceBrain : public Brain {
public:
    explicit LineTraceBrain(String tag = "LineTraceBrain");

    void SetCurrentCarState(LineTraceCarState car_state);

    Instruction *CalculateNextInstruction() override;

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
};

#endif // ZIGZAG_LINE_TRACE_BRAIN

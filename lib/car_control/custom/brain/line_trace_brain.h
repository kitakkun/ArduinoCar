#ifndef ZIGZAG_LINE_TRACE_BRAIN
#define ZIGZAG_LINE_TRACE_BRAIN

#include "core/logic/brain.h"
#include "custom/data_model/line_trace_car_state.h"

enum ZigZagLineTraceState {
    ready,
    searching,
    tracing,
    readyBack,
    searchingBack,
    tracingBack,
    FINISHED
};

enum LastInstruction {
    TorqueLeft, TorqueRight, Other,
};

class LineTraceBrain : public Brain {
public:
    LineTraceBrain(int base_speed, int torque_force);

    void SetCurrentCarState(LineTraceCarState car_state);

    Instruction *CalculateNextInstruction() override;

private:
    Instruction* Ready();
    Instruction* Search();
    Instruction* Trace();
    Instruction* ReadyBack();
    Instruction* SearchBack();
    Instruction* TraceBack();
    LineTraceCarState current_car_state_;
    int base_speed_;
    int torque_force_;
    ZigZagLineTraceState state_ = ready;
    unsigned long last_time_on_black_;
    LastInstruction last_instruction_ = Other;
};

#endif // ZIGZAG_LINE_TRACE_BRAIN

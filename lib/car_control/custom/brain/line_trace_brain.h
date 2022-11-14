#ifndef ZIGZAG_LINE_TRACE_BRAIN
#define ZIGZAG_LINE_TRACE_BRAIN

#include "core/logic/brain.h"
#include "custom/car/line_trace_car_state.h"

enum ZigZagLineTraceState {
    READY,
    SEARCHING_LINE,
    TRACING_LINE,
    READY_FOR_BACK,
    SEARCHING_BACK_LINE,
    TRACING_BACK_LINE,
    FINISHED
};

enum LastInstruction {
    TorqueLeft, TorqueRight, Other,
};

class LineTraceBrain : public Brain {
public:
    LineTraceBrain(int run_speed, int torque_force);

    void SetCurrentCarState(LineTraceCarState car_state);

    Instruction *CalculateNextInstruction() override;

private:
    LineTraceCarState current_car_state_;
    int run_speed_;
    int torque_force_;
    ZigZagLineTraceState state_ = READY;
    unsigned long trace_start_time_;
    LastInstruction last_instruction_ = Other;
};

#endif // ZIGZAG_LINE_TRACE_BRAIN

#ifndef ZIGZAG_LINE_TRACE_BRAIN
#define ZIGZAG_LINE_TRACE_BRAIN

#include "control/brain/brain.h"

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

class ZigZagLineTraceBrain : public Brain {
public:
    ZigZagLineTraceBrain(int run_speed, int torque_force);

    Instruction *CalculateNextInstruction(CarState state) override;

private:
    int run_speed_;
    int torque_force_;
    ZigZagLineTraceState state_ = READY;
    unsigned long trace_start_time_;
    LastInstruction last_instruction_ = Other;
};

#endif // ZIGZAG_LINE_TRACE_BRAIN

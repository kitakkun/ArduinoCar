#ifndef PID_LINE_TRACE_BRAIN
#define PID_LINE_TRACE_BRAIN

#include "control/brain/brain.h"

enum PidLineTraceState {
    READY, TRACING_LINE, FINISHED
};

class PidLineTraceBrain : public Brain {
public:
    PidLineTraceBrain(int run_speed, int torque_force);

    Instruction *CalculateNextInstruction(CarState state) override;

private:
    int run_speed_;
    int torque_force_;
    signed long diff_R[2];
    float integral_R;
    signed long diff_L[2];
    float integral_L;
    PidLineTraceState state_ = READY;
    float PID_left(signed short Senser_Value);
};

#endif // PID_LINE_TRACE_BRAIN

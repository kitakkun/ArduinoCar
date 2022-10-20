#ifndef ZIGZAG_LINE_TRACE_BRAIN
#define ZIGZAG_LINE_TRACE_BRAIN

#include "brain.h"

class ZigZagLineTraceBrain : public Brain {
public:
    ZigZagLineTraceBrain(int run_speed, int torque_force);

    Instruction *CalculateNextInstruction(CarState state) override;
private:
    int run_speed_;
    int torque_force_;
};

#endif // ZIGZAG_LINE_TRACE_BRAIN

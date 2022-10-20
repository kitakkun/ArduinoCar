#ifndef ZIGZAG_LINE_TRACE_BRAIN
#define ZIGZAG_LINE_TRACE_BRAIN

#include "brain.h"

class ZigZagLineTraceBrain : Brain {
public:
    Instruction * CalculateNextInstruction(CarState state) override;
};

#endif // ZIGZAG_LINE_TRACE_BRAIN

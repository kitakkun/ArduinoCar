#ifndef ZIGZAG_LINE_TRACE_BRAIN
#define ZIGZAG_LINE_TRACE_BRAIN

#include "brain.h"

class ZigZagLineTraceBrain : public Brain {
public:
    ZigZagLineTraceBrain();

    Instruction *CalculateNextInstruction(CarState state) override;
};

#endif // ZIGZAG_LINE_TRACE_BRAIN

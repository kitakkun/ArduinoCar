#ifndef LABORATORY_WORK_IN_INFORMATION_ENGINEERING_III_LINE_TRACE_GO_AND_BACK_BRAIN_H
#define LABORATORY_WORK_IN_INFORMATION_ENGINEERING_III_LINE_TRACE_GO_AND_BACK_BRAIN_H

#include "line_trace_brain.h"

class LineTraceGoAndBackBrain : public LineTraceBrain {
public:
    LineTraceGoAndBackBrain(int base_speed, int torque_force);

protected:
    Instruction *Ready() override;

    Instruction *Search() override;
    Instruction * Trace() override;
    Instruction * ReadyBack() override;
    Instruction * SearchBack() override;
    Instruction * TraceBack() override;

private:
    int base_speed_;
    int torque_force_;
    unsigned long last_time_on_black_;
};


#endif //LABORATORY_WORK_IN_INFORMATION_ENGINEERING_III_LINE_TRACE_GO_AND_BACK_BRAIN_H

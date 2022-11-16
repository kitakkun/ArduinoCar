#ifndef LABORATORY_WORK_IN_INFORMATION_ENGINEERING_III_LINE_TRACE_GO_AND_TURN_BACK_BRAIN_H
#define LABORATORY_WORK_IN_INFORMATION_ENGINEERING_III_LINE_TRACE_GO_AND_TURN_BACK_BRAIN_H

#include "line_trace_brain.h"

/**
 * 直線をトレースして、Uターンして戻ってくるアルゴリズム
 */
class LineTraceGoAndTurnBackBrain : public LineTraceBrain {
public:
    LineTraceGoAndTurnBackBrain(int base_speed, int forward_torque_force, String tag = "LineTraceGoAndTurnBackBrain");

protected:
    Instruction *Ready() override;

    Instruction *Search() override;

    Instruction *Trace() override;

    Instruction *ReadyBack() override;

    Instruction *SearchBack() override;

    Instruction *TraceBack() override;

    Instruction *Finish() override;

private:
    int base_speed_;
    int forward_torque_force_;
};


#endif //LABORATORY_WORK_IN_INFORMATION_ENGINEERING_III_LINE_TRACE_GO_AND_TURN_BACK_BRAIN_H

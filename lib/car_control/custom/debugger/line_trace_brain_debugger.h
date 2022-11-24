#ifndef LABORATORY_WORK_IN_INFORMATION_ENGINEERING_III_LINE_TRACE_BRAIN_DEBUGGER_H
#define LABORATORY_WORK_IN_INFORMATION_ENGINEERING_III_LINE_TRACE_BRAIN_DEBUGGER_H


#include "core/debug/debugger.h"
#include "custom/brain/line_trace_brain.h"

class LineTraceBrainDebugger : public Debugger {
public:
    explicit LineTraceBrainDebugger(LineTraceBrain *brain);

    void PrintDebugLog() override;

private:
    LineTraceBrain *brain_;
};


#endif //LABORATORY_WORK_IN_INFORMATION_ENGINEERING_III_LINE_TRACE_BRAIN_DEBUGGER_H

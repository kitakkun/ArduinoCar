#ifndef LABORATORY_WORK_IN_INFORMATION_ENGINEERING_III_WHEEL_DEBUGGER_H
#define LABORATORY_WORK_IN_INFORMATION_ENGINEERING_III_WHEEL_DEBUGGER_H


#include "debugger.h"
#include "core/component/wheel.h"

class WheelDebugger : public Debugger {
public:
    explicit WheelDebugger(Wheel *left_wheel, Wheel *right_wheel);

    void PrintDebugLog() override;

private:
    Wheel *left_wheel_;
    Wheel *right_wheel_;
};


#endif //LABORATORY_WORK_IN_INFORMATION_ENGINEERING_III_WHEEL_DEBUGGER_H

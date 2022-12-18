#ifndef LABORATORY_WORK_IN_INFORMATION_ENGINEERING_III_PID_GO_RETURN_TRACE_CONTROLLER_H
#define LABORATORY_WORK_IN_INFORMATION_ENGINEERING_III_PID_GO_RETURN_TRACE_CONTROLLER_H

#include "pid_trace_controller.h"
#include "trace_state.h"

/*
 * 行ってターンして戻ってくるトレースコントローラ
 */
class PidGoReturnTraceController : public PidTraceController {
public:
    explicit PidGoReturnTraceController(
        TraceCar *car,
        int base_speed,
        int lr_sensor_diff,
        int max_manipulation,
        float p_weight,
        float d_weight
    );

    void Operate() override;

private:
    TraceState state_;

    void Ready();

    void Trace() override;

    void Search();

    void ReadyBack();

    void SearchBack();

    void TraceBack();

    void Completed();

    void UpdateState(TraceState new_state);
};

#endif //LABORATORY_WORK_IN_INFORMATION_ENGINEERING_III_PID_GO_RETURN_TRACE_CONTROLLER_H

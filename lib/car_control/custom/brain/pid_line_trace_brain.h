#ifndef LABORATORY_WORK_IN_INFORMATION_ENGINEERING_III_PID_LINE_TRACE_BRAIN_H
#define LABORATORY_WORK_IN_INFORMATION_ENGINEERING_III_PID_LINE_TRACE_BRAIN_H

#include "line_trace_brain.h"

class PidLineTraceBrain : public LineTraceBrain {
public:
    /**
     * @param p
     * @param i
     * @param d
     * @param lr_sensor_diff (左のセンサ値 - 右のセンサ値)の値
     */
    PidLineTraceBrain(int base_speed, float p, float i, float d, int left_target_value, int right_target_value, int lr_sensor_diff, int max_deviation);

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
    int left_target_value_;
    int right_target_value_;
    float p_;
    float i_;
    float d_;
    int lr_sensor_diff_;
    int max_deviation_; // 最大の
};


#endif //LABORATORY_WORK_IN_INFORMATION_ENGINEERING_III_PID_LINE_TRACE_BRAIN_H

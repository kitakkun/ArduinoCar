#ifndef LABORATORY_WORK_IN_INFORMATION_ENGINEERING_III_PID_LINE_TRACE_BRAIN_H
#define LABORATORY_WORK_IN_INFORMATION_ENGINEERING_III_PID_LINE_TRACE_BRAIN_H

#include "line_trace_brain.h"

class PidLineTraceBrain : public LineTraceBrain {
public:
    /**
     * @param p p制御の重み（比例制御 普通の調整）
     * @param i i制御の重み（積分制御 今の所使わない）
     * @param d d制御の重み（微分制御 急なカーブへの対応など）
     * @param lr_sensor_diff 望ましい位置にあるときの(左のセンサ値 - 右のセンサ値)の値。個体値を吸収する役割。
     */
    PidLineTraceBrain(int base_speed, float p, float i, float d, int lr_sensor_diff, int max_deviation);

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
    float p_;
    float i_;
    float d_;
    int lr_sensor_diff_;
    int max_manipulation_;
    int prev_deviation_;
};


#endif //LABORATORY_WORK_IN_INFORMATION_ENGINEERING_III_PID_LINE_TRACE_BRAIN_H

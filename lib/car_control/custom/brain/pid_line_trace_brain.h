#ifndef LABORATORY_WORK_IN_INFORMATION_ENGINEERING_III_PID_LINE_TRACE_BRAIN_H
#define LABORATORY_WORK_IN_INFORMATION_ENGINEERING_III_PID_LINE_TRACE_BRAIN_H

#include "line_trace_brain.h"
#include "custom/data_model/trace_mode.h"

class PidLineTraceBrain : public LineTraceBrain {
public:
    /**
     * @param trace_mode トレースモード（行動パターンを決定）
     * @param base_speed 基本速度
     * @param turn_speed Uターン時の回転速度
     * @param p p制御の重み（比例制御 普通の調整）
     * @param d d制御の重み（微分制御 急なカーブへの対応など）
     * @param lr_sensor_diff 望ましい位置にあるときの(左のセンサ値 - 右のセンサ値)の値。個体値を吸収する役割。
     * @param max_manipulation 最大の速度操作量（制限）
     */
    PidLineTraceBrain(TraceMode trace_mode, int base_speed, int turn_speed, float p, float d, int lr_sensor_diff, int max_manipulation);

protected:
    Instruction *Ready() override;

    Instruction *Search() override;

    Instruction *Trace() override;

    Instruction *ReadyBack() override;

    Instruction *SearchBack() override;

    Instruction *TraceBack() override;

    Instruction *Finish() override;

private:
    TraceMode trace_mode_;
    int base_speed_;
    int turn_speed_;
    float p_;
    float d_;
    int lr_sensor_diff_;
    int max_manipulation_;
    int prev_deviation_;
    unsigned long last_time_called_;
};


#endif //LABORATORY_WORK_IN_INFORMATION_ENGINEERING_III_PID_LINE_TRACE_BRAIN_H

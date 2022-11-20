#include "pid_line_trace_brain.h"
#include "custom/instruction/force_speed_update_instruction.h"

Instruction *PidLineTraceBrain::Ready() {
    return nullptr;
}

Instruction *PidLineTraceBrain::Search() {
    return nullptr;
}

Instruction *PidLineTraceBrain::Trace() {
    /**
     * deviation > 0 => 左の方が黒に近付いている
     * deviation < 0 => 右の方が黒に近付いている
     * この差分を用いて単純な比例制御を行う（P制御）
     */

    int deviation = (int)(p_ * (current_car_state_.front_left_reflector_raw_ - current_car_state_.front_right_reflector_raw_ - lr_sensor_diff_));
    // 値の範囲を制限
    deviation = constrain(deviation, -max_deviation_, max_deviation_);

    return new ForceSpeedUpdateInstruction(base_speed_ + deviation, base_speed_ + deviation);
}

Instruction *PidLineTraceBrain::ReadyBack() {
    return nullptr;
}

Instruction *PidLineTraceBrain::SearchBack() {
    return nullptr;
}

Instruction *PidLineTraceBrain::TraceBack() {
    return nullptr;
}

Instruction *PidLineTraceBrain::Finish() {
    return nullptr;
}

PidLineTraceBrain::PidLineTraceBrain(int base_speed, float p, float i, float d, int left_target_value, int right_target_value, int lr_sensor_diff, int max_deviation) {
    this->base_speed_ = base_speed;
    this->p_ = p;
    this->i_ = i;
    this->d_ = d;
    this->left_target_value_ = left_target_value;
    this->right_target_value_ = right_target_value;
    this->lr_sensor_diff_ = lr_sensor_diff;
    this->max_deviation_ = max_deviation;
}

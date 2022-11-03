#include "stop_instruction.h"

StopInstruction::StopInstruction(int duration_millis) {
    this->duration_millis_ = duration_millis;
}

int StopInstruction::runCoroutine() {
    COROUTINE_BEGIN();
    start_left_speed_ = left_wheel_->Speed();
    start_right_speed_ = right_wheel_->Speed();
    left_unit_decelerate_amount_ = start_left_speed_ / duration_millis_;  /// 左車輪の減速量
    right_unit_decelerate_amount_ = start_right_speed_ / duration_millis_;  /// 右車輪の減速量

    while (left_wheel_->Speed() > 0 || right_wheel_->Speed() > 0) {
        left_wheel_->Decelerate(left_unit_decelerate_amount_);
        right_wheel_->Decelerate(right_unit_decelerate_amount_);
        COROUTINE_DELAY(1);
    }
    COROUTINE_END();
}

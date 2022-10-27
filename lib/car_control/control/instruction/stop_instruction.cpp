#include "stop_instruction.h"

void StopInstruction::Run(Wheel *left_wheel, Wheel *right_wheel) {
    double l_speed = left_wheel->Speed();    /// 左車輪の速度
    double r_speed = right_wheel->Speed();    /// 右車輪の速度

    double l_amount = l_speed / duration_millis_;  /// 左車輪の減速量
    double r_amount = r_speed / duration_millis_;  /// 右車輪の減速量
    
    while (l_speed > 0 || r_speed > 0) {
        left_wheel->Decelerate(l_amount);
        right_wheel->Decelerate(r_amount);
        l_speed = left_wheel->Speed();
        r_speed = right_wheel->Speed();
        delay(1);
    }
}

StopInstruction::StopInstruction(int duration_millis) {
    this->duration_millis_ = duration_millis;
}
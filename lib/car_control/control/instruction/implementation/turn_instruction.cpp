#include "turn_instruction.h"

int TurnInstruction::runCoroutine() {
    COROUTINE_BEGIN();
    left_wheel_->UpdateDirection(backward); /// 左車輪を後ろ方向に回転させる
    left_wheel_->UpdateSpeed(speed_);
    right_wheel_->UpdateDirection(forward); /// 右車輪を前方向に回転させる
    right_wheel_->UpdateSpeed(speed_);
    left_wheel_->Apply();
    right_wheel_->Apply();
    COROUTINE_DELAY(duration_);
    left_wheel_->UpdateSpeed(0);
    right_wheel_->UpdateSpeed(0);
    left_wheel_->Apply();
    right_wheel_->Apply();
    COROUTINE_END();
}

TurnInstruction::TurnInstruction(int speed, int duration) {
    speed_ = speed;
    duration_ = duration;
}

/* TODO: 走行時間を指定し，180度回転するようにする */
/* TODO: 回転前の状態(Direction)を記憶し，回転後に，回転前の状態へ戻す？ */


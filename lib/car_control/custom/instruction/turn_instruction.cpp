#include "turn_instruction.h"

TurnInstruction::TurnInstruction(int speed, int duration, InstructionMode mode) {
    this->speed_ = speed;
    this->duration_ = duration;
    this->mode_ = mode;
}

int TurnInstruction::Run(Wheel *left_wheel, Wheel *right_wheel) {
    COROUTINE_BEGIN();
    left_wheel->UpdateDirection(backward); /// 左車輪を後ろ方向に回転させる
    left_wheel->UpdateSpeed(speed_);
    right_wheel->UpdateDirection(forward); /// 右車輪を前方向に回転させる
    right_wheel->UpdateSpeed(speed_);
    COROUTINE_DELAY(duration_);
    left_wheel->UpdateSpeed(0);
    right_wheel->UpdateSpeed(0);
    COROUTINE_END();
}

/* TODO: 走行時間を指定し，180度回転するようにする */
/* TODO: 回転前の状態(Direction)を記憶し，回転後に，回転前の状態へ戻す？ */


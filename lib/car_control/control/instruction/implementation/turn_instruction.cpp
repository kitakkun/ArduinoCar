#include "turn_instruction.h"

void TurnInstruction::Run(Wheel *left_wheel, Wheel *right_wheel) {
    left_wheel->UpdateDirection(backward); /// 左車輪を後ろ方向に回転させる
    left_wheel->UpdateSpeed(100 /* 任意の速さ */);

    right_wheel->UpdateSpeed(100 /* 任意の速さ */); /// 右車輪を前方向に回転させる
}

/* 走行時間を指定し，180度回転するようにする */


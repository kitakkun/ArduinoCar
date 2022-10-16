#ifndef CAR_STATE_H
#define CAR_STATE_H

#include "paper_color.h"
#include "move_direction.h"

/**
 * 車の状態データ
 */
struct CarState {
    int lw_speed;           // 左車輪のスピード
    int rw_speed;           // 右車輪のスピード
    MoveDirection lw_direction; // 左車輪の回転方向
    MoveDirection rw_direction; // 右車輪の回転方向
    PaperColor front_color;     // 前方センサーの色
    PaperColor right_color;     // 右センサーの色
    PaperColor left_color;      // 左センサーの色
};

#endif //CAR_STATE_H

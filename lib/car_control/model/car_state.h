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
    PaperColor front_color;     // 中央センサーの色
    PaperColor right_color;     // 右センサーの色
    PaperColor left_color;      // 左センサーの色
    int front_raw;      // 中央センサーの生の値
    int right_raw;      // 右センサーの生の値
    int left_raw;       // 左センサーの生の値
};

#endif //CAR_STATE_H

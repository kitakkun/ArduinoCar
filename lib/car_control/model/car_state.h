#ifndef CAR_STATE_H
#define CAR_STATE_H

#include "model/paper_color.h"
#include "model/move_direction.h"

/**
 * 車の状態データ
 */
struct CarState {
    int left_wheel_speed;           // 左車輪のスピード
    int right_wheel_speed;           // 右車輪のスピード
    MoveDirection left_wheel_direction; // 左車輪の回転方向
    MoveDirection right_wheel_direction; // 右車輪の回転方向
    PaperColor front_mid_reflector_color;     // 中央センサーの色
    PaperColor front_right_reflector_color;     // 右センサーの色
    PaperColor front_left_reflector_color;      // 左センサーの色
    PaperColor back_mid_reflector_color;     // 中央センサーの色
    PaperColor back_right_reflector_color;     // 右センサーの色
    PaperColor back_left_reflector_color;      // 左センサーの色
    int front_mid_reflector_raw;      // 中央センサーの生の値
    int front_right_reflector_raw;      // 右センサーの生の値
    int front_left_reflector_raw;       // 左センサーの生の値
    int back_mid_reflector_raw;      // 中央センサーの生の値
    int back_right_reflector_raw;      // 右センサーの生の値
    int back_left_reflector_raw;       // 左センサーの生の値
};

#endif //CAR_STATE_H

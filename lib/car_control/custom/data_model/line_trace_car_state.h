#ifndef LABORATORY_WORK_IN_INFORMATION_ENGINEERING_III_LINE_TRACE_CAR_STATE_H
#define LABORATORY_WORK_IN_INFORMATION_ENGINEERING_III_LINE_TRACE_CAR_STATE_H

#include "core/data_model/binary_color.h"
#include "core/data_model/move_direction.h"
#include "core/component/wheel_impl.h"
#include "core/component/photo_reflector_impl.h"

class LineTraceCarState {
public:
    LineTraceCarState();

    LineTraceCarState(
            int left_wheel_speed,
            int right_wheel_speed,
            MoveDirection left_wheel_direction,
            MoveDirection right_wheel_direction,
            BinaryColor front_mid_reflector_color,
            BinaryColor front_left_reflector_color,
            BinaryColor front_right_reflector_color,
            BinaryColor back_mid_reflector_color,
            BinaryColor back_left_reflector_color,
            BinaryColor back_right_reflector_color,
            int front_mid_reflector_raw,
            int front_left_reflector_raw,
            int front_right_reflector_raw,
            int back_mid_reflector_raw,
            int back_left_reflector_raw,
            int back_right_reflector_raw
    );

    bool IsAnyBlack() const;

    bool IsAnyFrontBlack() const;

    bool IsAnyBackBlack() const;

    bool IsAnyWhite() const;

    bool IsAnyFrontWhite() const;

    bool IsAnyBackWhite() const;

    bool IsAllWhite() const;

    bool IsAllFrontWhite() const;

    bool IsAllBackWhite() const;

    bool IsAllBlack() const;

    bool IsAllFrontBlack() const;

    bool IsAllBackBlack() const;

    int left_wheel_speed_;           // 左車輪のスピード
    int right_wheel_speed_;           // 右車輪のスピード
    MoveDirection left_wheel_direction_; // 左車輪の回転方向
    MoveDirection right_wheel_direction_; // 右車輪の回転方向
    BinaryColor front_mid_reflector_color_;     // 中央センサーの色
    BinaryColor front_left_reflector_color_;      // 左センサーの色
    BinaryColor front_right_reflector_color_;     // 右センサーの色
    BinaryColor back_mid_reflector_color_;     // 中央センサーの色
    BinaryColor back_left_reflector_color_;      // 左センサーの色
    BinaryColor back_right_reflector_color_;     // 右センサーの色
    int front_mid_reflector_raw_;      // 中央センサーの生の値
    int front_left_reflector_raw_;       // 左センサーの生の値
    int front_right_reflector_raw_;      // 右センサーの生の値
    int back_mid_reflector_raw_;      // 中央センサーの生の値
    int back_left_reflector_raw_;       // 左センサーの生の値
    int back_right_reflector_raw_;      // 右センサーの生の値
};

#endif //LABORATORY_WORK_IN_INFORMATION_ENGINEERING_III_LINE_TRACE_CAR_STATE_H

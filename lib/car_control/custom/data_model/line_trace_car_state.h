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
            BinaryColor mid_reflector_color,
            BinaryColor left_reflector_color,
            BinaryColor right_reflector_color,
            int mid_reflector_raw,
            int left_reflector_raw,
            int right_reflector_raw
    );

    bool IsAnyBlack() const;

    bool IsAnyWhite() const;

    bool IsAllWhite() const;

    bool IsAllBlack() const;

    int left_wheel_speed_;           // 左車輪のスピード
    int right_wheel_speed_;           // 右車輪のスピード
    MoveDirection left_wheel_direction_; // 左車輪の回転方向
    MoveDirection right_wheel_direction_; // 右車輪の回転方向
    BinaryColor mid_reflector_color_;     // 中央センサーの色
    BinaryColor left_reflector_color_;      // 左センサーの色
    BinaryColor right_reflector_color;     // 右センサーの色
    int mid_reflector_raw_;      // 中央センサーの生の値
    int left_reflector_raw_;       // 左センサーの生の値
    int right_reflector_raw_;      // 右センサーの生の値
};

#endif //LABORATORY_WORK_IN_INFORMATION_ENGINEERING_III_LINE_TRACE_CAR_STATE_H

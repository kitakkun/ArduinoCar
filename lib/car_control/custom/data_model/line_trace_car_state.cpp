#include "line_trace_car_state.h"

bool LineTraceCarState::IsAnyBlack() const {
    return mid_reflector_color_ == black ||
           left_reflector_color_ == black ||
           right_reflector_color == black;
}

bool LineTraceCarState::IsAnyWhite() const {
    return mid_reflector_color_ == white ||
           left_reflector_color_ == white ||
           right_reflector_color == white;
}

bool LineTraceCarState::IsAllWhite() const {
    return mid_reflector_color_ == white &&
           left_reflector_color_ == white &&
           right_reflector_color == white;
}

bool LineTraceCarState::IsAllBlack() const {
    return mid_reflector_color_ == black &&
           left_reflector_color_ == black &&
           right_reflector_color == black;
}

LineTraceCarState::LineTraceCarState(
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
) {
    this->left_wheel_speed_ = left_wheel_speed;
    this->right_wheel_speed_ = right_wheel_speed;
    this->left_wheel_direction_ = left_wheel_direction;
    this->right_wheel_direction_ = right_wheel_direction;

    this->right_reflector_color = right_reflector_color;
    this->left_reflector_color_ = left_reflector_color;
    this->mid_reflector_color_ = mid_reflector_color;

    this->right_reflector_raw_ = right_reflector_raw;
    this->left_reflector_raw_ = left_reflector_raw;
    this->mid_reflector_raw_ = mid_reflector_raw;
}

LineTraceCarState::LineTraceCarState() {
    this->left_wheel_speed_ = 0;
    this->right_wheel_speed_ = 0;
    this->left_wheel_direction_ = forward;
    this->right_wheel_direction_ = forward;
    this->mid_reflector_color_ = white;
    this->left_reflector_color_ = white;
    this->right_reflector_color = white;
    this->right_reflector_color = white;
    this->mid_reflector_raw_ = 0;
    this->left_reflector_raw_ = 0;
    this->right_reflector_raw_ = 0;
}

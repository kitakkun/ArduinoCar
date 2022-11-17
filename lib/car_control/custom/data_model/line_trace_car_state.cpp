#include "line_trace_car_state.h"

bool LineTraceCarState::IsAnyBlack() const {
    return IsAnyFrontBlack() || IsAnyBackBlack();
}

bool LineTraceCarState::IsAnyFrontBlack() const {
    return front_mid_reflector_color_ == black ||
           front_left_reflector_color_ == black ||
           front_right_reflector_color_ == black;
}

bool LineTraceCarState::IsAnyBackBlack() const {
    return back_mid_reflector_color_ == black ||
           back_left_reflector_color_ == black ||
           back_right_reflector_color_ == black;
}

bool LineTraceCarState::IsAnyWhite() const {
    return IsAnyFrontWhite() || IsAnyBackWhite();
}

bool LineTraceCarState::IsAnyFrontWhite() const {
    return front_mid_reflector_color_ == white ||
           front_left_reflector_color_ == white ||
           front_right_reflector_color_ == white;
}

bool LineTraceCarState::IsAnyBackWhite() const {
    return back_mid_reflector_color_ == white ||
           back_left_reflector_color_ == white ||
           back_right_reflector_color_ == white;
}

bool LineTraceCarState::IsAllWhite() const {
    return IsAllFrontWhite() && IsAllBackWhite();
}

bool LineTraceCarState::IsAllFrontWhite() const {
    return front_mid_reflector_color_ == white &&
           front_left_reflector_color_ == white &&
           front_right_reflector_color_ == white;
}

bool LineTraceCarState::IsAllBackWhite() const {
    return back_mid_reflector_color_ == white &&
           back_left_reflector_color_ == white &&
           back_right_reflector_color_ == white;
}

bool LineTraceCarState::IsAllBlack() const {
    return IsAllFrontBlack() && IsAllBackBlack();
}

bool LineTraceCarState::IsAllFrontBlack() const {
    return front_mid_reflector_color_ == black &&
           front_left_reflector_color_ == black &&
           front_right_reflector_color_ == black;
}

bool LineTraceCarState::IsAllBackBlack() const {
    return back_mid_reflector_color_ == black &&
           back_left_reflector_color_ == black &&
           back_right_reflector_color_ == black;
}

LineTraceCarState::LineTraceCarState(
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
) {
    this->left_wheel_speed_ = left_wheel_speed;
    this->right_wheel_speed_ = right_wheel_speed;
    this->left_wheel_direction_ = left_wheel_direction;
    this->right_wheel_direction_ = right_wheel_direction;

    this->front_right_reflector_color_ = front_right_reflector_color;
    this->front_left_reflector_color_ = front_left_reflector_color;
    this->front_mid_reflector_color_ = front_mid_reflector_color;
    this->back_right_reflector_color_ = back_right_reflector_color;
    this->back_left_reflector_color_ = back_left_reflector_color;
    this->back_mid_reflector_color_ = back_mid_reflector_color;

    this->front_right_reflector_raw_ = front_right_reflector_raw;
    this->front_left_reflector_raw_ = front_left_reflector_raw;
    this->front_mid_reflector_raw_ = front_mid_reflector_raw;
    this->back_right_reflector_raw_ = back_right_reflector_raw;
    this->back_left_reflector_raw_ = back_left_reflector_raw;
    this->back_mid_reflector_raw_ = back_mid_reflector_raw;
}

LineTraceCarState::LineTraceCarState() {
    this->left_wheel_speed_ = 0;
    this->right_wheel_speed_ = 0;
    this->left_wheel_direction_ = forward;
    this->right_wheel_direction_ = forward;
    this->front_mid_reflector_color_ = white;
    this->front_left_reflector_color_ = white;
    this->front_right_reflector_color_ = white;
    this->back_mid_reflector_color_ = white;
    this->back_left_reflector_color_ = white;
    this->back_right_reflector_color_ = white;
    this->front_right_reflector_color_ = white;
    this->front_mid_reflector_raw_ = 0;
    this->front_left_reflector_raw_ = 0;
    this->front_right_reflector_raw_ = 0;
    this->back_mid_reflector_raw_ = 0;
    this->back_left_reflector_raw_ = 0;
    this->back_right_reflector_raw_ = 0;
    this->front_right_reflector_raw_ = 0;
}

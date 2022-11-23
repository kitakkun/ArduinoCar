#include "line_trace_continuous_brain.h"
#include "custom/instructions.h"
#include "core/debug/logger.h"

LineTraceContinuousBrain::LineTraceContinuousBrain(
        int base_speed, int torque_force, String tag
) : LineTraceBrain(tag) {
    this->base_speed_ = base_speed;
    this->torque_force_ = torque_force;
}

Instruction *LineTraceContinuousBrain::Ready() {
    // 発進してライン探索モードに移行
    Logger::Verboseln(this, F("READY... STARTING SEARCH MODE"));
    this->activity_state_ = searching;
    return new UpdateSpeedInstruction(base_speed_);
}

Instruction *LineTraceContinuousBrain::Search() {
    Logger::Verboseln(this, F("SEARCHING LINE..."));
    if (current_car_state_.IsAnyFrontBlack()) {
        Logger::Verboseln(this, F("LINE FOUND! STARTING TRACE MODE..."));
        activity_state_ = tracing;
        return new ForceStopInstruction();
    }
    return new UpdateSpeedInstruction(base_speed_);
}

Instruction *LineTraceContinuousBrain::Trace() {

    // スピードが0なら発進
    if (current_car_state_.left_wheel_speed_ == 0 || current_car_state_.right_wheel_speed_ == 0) {
        return new UpdateSpeedInstruction(base_speed_);
    }

    // 左が黒なら左へ曲がる
    if (current_car_state_.front_left_reflector_color_ == black) {
        return new TorqueLeftInstruction(base_speed_, torque_force_, interrupt);
    }
    // 右が黒なら右へ曲がる
    if (current_car_state_.front_right_reflector_color_ == black) {
        return new TorqueRightInstruction(base_speed_, torque_force_, interrupt);
    }
    // 真ん中が黒なら直進
    if (current_car_state_.front_mid_reflector_color_ == black) {
        return new UpdateSpeedInstruction(base_speed_);
    }

    // 前方が使えないとき、後方のセンサーで判断する
    // 左が黒なら左へ曲がる
    if (current_car_state_.back_left_reflector_color_ == black) {
        return new TorqueLeftInstruction(base_speed_, torque_force_, interrupt);
    }
    // 右が黒なら右へ曲がる
    if (current_car_state_.back_right_reflector_color_ == black) {
        return new TorqueRightInstruction(base_speed_, torque_force_, interrupt);
    }
    // 真ん中が黒なら直進
    if (current_car_state_.back_mid_reflector_color_ == black) {
        return new UpdateSpeedInstruction(base_speed_);
    }

    return new UpdateSpeedInstruction(base_speed_);
}

Instruction *LineTraceContinuousBrain::ReadyBack() {
    // do nothing
    return new WaitInstruction(10);
}

Instruction *LineTraceContinuousBrain::SearchBack() {
    // do nothing
    return new WaitInstruction(10);
}

Instruction *LineTraceContinuousBrain::TraceBack() {
    // do nothing
    return new WaitInstruction(10);
}

Instruction *LineTraceContinuousBrain::Finish() {
    // do nothing
    return new WaitInstruction(10);
}

#include "line_trace_go_and_back_brain.h"
#include "custom/instructions.h"
#include "core/debug/logger.h"

LineTraceGoAndBackBrain::LineTraceGoAndBackBrain(int base_speed, int torque_force, String tag) : LineTraceBrain(tag) {
    this->base_speed_ = base_speed;
    this->torque_force_ = torque_force;
    this->last_time_on_black_ = 0;
}

Instruction *LineTraceGoAndBackBrain::Ready() {
    // 発進してライン探索モードに移行
    Logger::Verboseln(this, "READY... STARTING SEARCH MODE");
    this->activity_state_ = searching;
    return new ForceSpeedUpdateInstruction(base_speed_);
}

Instruction *LineTraceGoAndBackBrain::Search() {
    Logger::Verboseln(this, "SEARCHING LINE...");
    if (current_car_state_.IsAnyFrontBlack()) {
        Logger::Verboseln(this, "LINE FOUND! STARTING TRACE MODE...");
        last_time_on_black_ = millis();
        activity_state_ = tracing;
        return new ForceStopInstruction();
    }
    return new ForceSpeedUpdateInstruction(base_speed_);
}

Instruction *LineTraceGoAndBackBrain::Trace() {

    if (current_car_state_.IsAnyFrontBlack()) {
        last_time_on_black_ = millis();
    }

    unsigned long current_time = millis();

    // スピードが0なら発進
    if (current_car_state_.left_wheel_speed_ == 0 || current_car_state_.right_wheel_speed_ == 0) {
        return new ForceSpeedUpdateInstruction(base_speed_);
    }

    // 前後全部白で一定時間経過したらトレース完了とみなしバックモードへ（一旦停止）
    if (current_car_state_.IsAllWhite() && current_time - last_time_on_black_ > 500) {
        Logger::Verboseln(this, "TRACING COMPLETED! STARTING READY_BACK MODE...");
        activity_state_ = readyBack;
        return new ForceStopInstruction(interrupt);
    }

    // 左が黒なら左へ曲がる
    if (current_car_state_.front_left_reflector_color_ == black) {
        return new TorqueLeftInstruction(base_speed_, torque_force_, 30, interrupt);
    }
    // 右が黒なら右へ曲がる
    if (current_car_state_.front_right_reflector_color_ == black) {
        return new TorqueRightInstruction(base_speed_, torque_force_, 30, interrupt);
    }
    // 真ん中が黒なら直進
    if (current_car_state_.front_mid_reflector_color_ == black) {
        return new ForceSpeedUpdateInstruction(base_speed_);
    }

    return new ForceSpeedUpdateInstruction(base_speed_);
}

Instruction *LineTraceGoAndBackBrain::ReadyBack() {
    Logger::Verboseln(this, "READY BACKING... STARTING SEARCH_BACK MODE");
    last_time_on_black_ = millis();
    this->activity_state_ = searchingBack;
    return new UpdateDirectionInstruction(backward);
}

Instruction *LineTraceGoAndBackBrain::SearchBack() {
    Logger::Verboseln(this, "SEARCHING BACK LINE...");
    if (current_car_state_.IsAnyBackBlack()) {
        Logger::Verboseln(this, "LINE FOUND! STARTING TRACE_BACK MODE");
        last_time_on_black_ = millis();
        activity_state_ = tracingBack;
        return new ForceStopInstruction();
    }
    return new ForceSpeedUpdateInstruction(base_speed_);
}

Instruction *LineTraceGoAndBackBrain::TraceBack() {
    unsigned long current_time = millis();

    if (current_car_state_.left_wheel_speed_ == 0 || current_car_state_.right_wheel_speed_ == 0) {
        return new ForceSpeedUpdateInstruction(base_speed_, base_speed_);
    }

    if (current_car_state_.IsAllBackWhite() && current_time - last_time_on_black_ > 1000) {
        Logger::Verboseln(this, "TRACING COMPLETED!");
        Logger::Verboseln(this, "FINISHED LINE TRACE TASK.");
        activity_state_ = finished;
        return new ForceStopInstruction();
    }

    if (current_car_state_.back_left_reflector_color_ == black) {
        last_time_on_black_ = millis();
        return new TorqueRightInstruction(base_speed_, torque_force_ - 15, 30, interrupt);
    }
    if (current_car_state_.back_right_reflector_color_ == black) {
        last_time_on_black_ = millis();
        return new TorqueLeftInstruction(base_speed_, torque_force_ - 15, 30, interrupt);
    }
    if (current_car_state_.back_mid_reflector_color_ == black) {
        last_time_on_black_ = millis();
        return new ForceSpeedUpdateInstruction(base_speed_ - 15, base_speed_);
    }

    return new ForceSpeedUpdateInstruction(base_speed_, base_speed_);
}

Instruction *LineTraceGoAndBackBrain::Finish() {
    return new ForceStopInstruction();
}

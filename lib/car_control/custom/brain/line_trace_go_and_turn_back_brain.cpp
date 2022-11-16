#include "line_trace_go_and_turn_back_brain.h"
#include "custom/instructions.h"
#include "core/debug/logger.h"
#include "custom/instruction/turn_instruction.h"

LineTraceGoAndTurnBackBrain::LineTraceGoAndTurnBackBrain(int base_speed, int forward_torque_force, String tag)
        : LineTraceBrain(tag) {
    this->base_speed_ = base_speed;
    this->forward_torque_force_ = forward_torque_force;
}

Instruction *LineTraceGoAndTurnBackBrain::Ready() {
    // 発進してライン探索モードに移行
    Logger::Verboseln(this, F("READY... STARTING SEARCH MODE"));
    this->activity_state_ = searching;
    return new ForceSpeedUpdateInstruction(base_speed_);
}

Instruction *LineTraceGoAndTurnBackBrain::Search() {
    Logger::Verboseln(this, F("SEARCHING LINE..."));
    if (current_car_state_.IsAnyFrontBlack()) {
        Logger::Verboseln(this, F("LINE FOUND! STARTING TRACE MODE..."));
        activity_state_ = tracing;
        return new ForceStopInstruction();
    }
    return new ForceSpeedUpdateInstruction(base_speed_);
}

Instruction *LineTraceGoAndTurnBackBrain::Trace() {

    // スピードが0なら発進
    if (current_car_state_.left_wheel_speed_ == 0 || current_car_state_.right_wheel_speed_ == 0) {
        return new ForceSpeedUpdateInstruction(base_speed_);
    }

    // 前後全部白になったらトレース完了とみなしバックモードへ（一旦停止）
    if (current_car_state_.IsAllWhite()) {
        Logger::Verboseln(this, F("TRACING COMPLETED! STARTING READY_BACK MODE..."));
        activity_state_ = readyBack;
        return new ForceStopInstruction(interrupt);
    }

    // 左が黒なら左へ曲がる
    if (current_car_state_.front_left_reflector_color_ == black) {
        return new TorqueLeftInstruction(base_speed_, forward_torque_force_, interrupt);
    }
    // 右が黒なら右へ曲がる
    if (current_car_state_.front_right_reflector_color_ == black) {
        return new TorqueRightInstruction(base_speed_, forward_torque_force_, interrupt);
    }
    // 真ん中が黒なら直進
    if (current_car_state_.front_mid_reflector_color_ == black) {
        return new ForceSpeedUpdateInstruction(base_speed_);
    }

    // 前方が使えないとき、後方のセンサーで判断する
    // 左が黒なら左へ曲がる
    if (current_car_state_.back_left_reflector_color_ == black) {
        return new TorqueLeftInstruction(base_speed_, forward_torque_force_, interrupt);
    }
    // 右が黒なら右へ曲がる
    if (current_car_state_.back_right_reflector_color_ == black) {
        return new TorqueRightInstruction(base_speed_, forward_torque_force_, interrupt);
    }
    // 真ん中が黒なら直進
    if (current_car_state_.back_mid_reflector_color_ == black) {
        return new ForceSpeedUpdateInstruction(base_speed_);
    }

    return new ForceSpeedUpdateInstruction(base_speed_);
}

Instruction *LineTraceGoAndTurnBackBrain::ReadyBack() {
    Logger::Verboseln(this, F("READY BACKING... STARTING SEARCH_BACK MODE"));
    this->activity_state_ = searchingBack;
    /* TODO: 360度回転になるように調整必要かも？ただ完全に白になる前に止まってれば回転してそのまま黒が見つかるはずなので、調整いらなくなるかも */
    return new TurnInstruction(120, 1000);
}

Instruction *LineTraceGoAndTurnBackBrain::SearchBack() {
    Logger::Verboseln(this, F("SEARCHING BACK LINE..."));
    if (current_car_state_.IsAnyFrontBlack()) {
        Logger::Verboseln(this, F("LINE FOUND! STARTING TRACE_BACK MODE"));
        activity_state_ = tracingBack;
        return new ForceStopInstruction(interrupt);
    }
    return new ForceSpeedUpdateInstruction(base_speed_);
}

Instruction *LineTraceGoAndTurnBackBrain::TraceBack() {

    if (current_car_state_.left_wheel_direction_ != current_car_state_.right_wheel_direction_) {
        return new UpdateDirectionInstruction(forward);
    }

    if (current_car_state_.left_wheel_speed_ == 0 || current_car_state_.right_wheel_speed_ == 0) {
        return new ForceSpeedUpdateInstruction(base_speed_, base_speed_);
    }

    if (current_car_state_.IsAllWhite()) {
        Logger::Verboseln(this, F("TRACING COMPLETED!"));
        Logger::Verboseln(this, F("FINISHED LINE TRACE TASK."));
        activity_state_ = finished;
        return new ForceStopInstruction();
    }

    // 左が黒なら左へ曲がる
    if (current_car_state_.front_left_reflector_color_ == black) {
        return new TorqueLeftInstruction(base_speed_, forward_torque_force_, interrupt);
    }
    // 右が黒なら右へ曲がる
    if (current_car_state_.front_right_reflector_color_ == black) {
        return new TorqueRightInstruction(base_speed_, forward_torque_force_, interrupt);
    }
    // 真ん中が黒なら直進
    if (current_car_state_.front_mid_reflector_color_ == black) {
        return new ForceSpeedUpdateInstruction(base_speed_);
    }

    // 前方が使えないとき、後方のセンサーで判断する
    // 左が黒なら左へ曲がる
    if (current_car_state_.back_left_reflector_color_ == black) {
        return new TorqueLeftInstruction(base_speed_, forward_torque_force_, interrupt);
    }
    // 右が黒なら右へ曲がる
    if (current_car_state_.back_right_reflector_color_ == black) {
        return new TorqueRightInstruction(base_speed_, forward_torque_force_, interrupt);
    }
    // 真ん中が黒なら直進
    if (current_car_state_.back_mid_reflector_color_ == black) {
        return new ForceSpeedUpdateInstruction(base_speed_);
    }

    return new ForceSpeedUpdateInstruction(base_speed_, base_speed_);
}

Instruction *LineTraceGoAndTurnBackBrain::Finish() {
    return new ForceStopInstruction();
}

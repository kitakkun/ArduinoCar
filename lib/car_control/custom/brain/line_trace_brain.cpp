#include "line_trace_brain.h"
#include "custom/instructions.h"
#include "ArduinoLog.h"
#include "core/data_model/binary_color.h"
#include "custom/debug/logger.h"

LineTraceBrain::LineTraceBrain(int base_speed, int torque_force) {
    this->base_speed_ = base_speed;
    this->torque_force_ = torque_force;
}

void LineTraceBrain::SetCurrentCarState(LineTraceCarState car_state) {
    Logger::LogLineTraceCarState(car_state);
    current_car_state_ = car_state;
}

Instruction *LineTraceBrain::CalculateNextInstruction() {
    switch (state_) {
        case ready:
            return Ready();
        case searching:
            return Search();
        case tracing:
            return Trace();
        case readyBack:
            return ReadyBack();
        case searchingBack:
            return SearchBack();
        case tracingBack:
            return TraceBack();
        default:
            return new ForceStopInstruction();
    }
}

// 準備中（行き）
Instruction *LineTraceBrain::Ready() {
    // 発進してライン探索モードに移行
    this->state_ = searching;
    return new ForceSpeedUpdateInstruction(base_speed_, base_speed_);
}

// 黒線探索モード（行き）
Instruction *LineTraceBrain::Search() {
    // どれか一つのセンサーが黒になったらトレース開始・一旦停止
    if (current_car_state_.IsAnyFrontBlack()) {
        last_time_on_black_ = millis();
        state_ = tracing;
        return new ForceStopInstruction();
    }
    return new WaitInstruction(10);
}

// トレース中（行き）
Instruction *LineTraceBrain::Trace() {

    if (current_car_state_.IsAnyFrontBlack()) {
        last_time_on_black_ = millis();
    }

    unsigned long current_time = millis();

    // スピードが0なら発進
    if (current_car_state_.left_wheel_speed_ == 0 || current_car_state_.right_wheel_speed_ == 0) {
        return new ForceSpeedUpdateInstruction(base_speed_, base_speed_);
    }

    // 全部白で一定時間経過したらトレース完了とみなしバックモードへ（一旦停止）
    if (current_car_state_.IsAllFrontWhite() && current_time - last_time_on_black_ > 1500) {
        state_ = readyBack;
        return new ForceStopInstruction();
    }

    // 左が黒なら左へ曲がる
    if (current_car_state_.front_left_reflector_color_ == black) {
        return new TorqueLeftInstruction(torque_force_, 30);
    }
    // 右が黒なら右へ曲がる
    if (current_car_state_.front_right_reflector_color_ == black) {
        return new TorqueRightInstruction(torque_force_, 30);
    }
    // 真ん中が黒なら直進
    if (current_car_state_.front_mid_reflector_color_ == black) {
        return new ForceSpeedUpdateInstruction(base_speed_, base_speed_);
    }

    return new ForceSpeedUpdateInstruction(base_speed_, base_speed_);
}

Instruction *LineTraceBrain::ReadyBack() {
    last_time_on_black_ = millis();
    this->state_ = searchingBack;
    return new UpdateDirectionInstruction(backward);
}

Instruction *LineTraceBrain::SearchBack() {
    if (current_car_state_.IsAnyFrontBlack()) {
        last_time_on_black_ = millis();
        state_ = tracingBack;
        return new ForceStopInstruction();
    }
    return new ForceSpeedUpdateInstruction(base_speed_, base_speed_);
}

Instruction *LineTraceBrain::TraceBack() {
    unsigned long current_time = millis();
    if (current_car_state_.left_wheel_speed_ == 0 || current_car_state_.right_wheel_speed_ == 0) {
        return new ForceSpeedUpdateInstruction(base_speed_, base_speed_);
    }

    if (current_car_state_.front_mid_reflector_color_ == white &&
        current_car_state_.front_left_reflector_color_ == white &&
        current_car_state_.front_right_reflector_color_ == white) {
        if (current_time - last_time_on_black_ > 1000) {
            state_ = FINISHED;
            return new ForceStopInstruction();
        } else {
            if (last_instruction_ == TorqueRight) {
                last_instruction_ = TorqueRight;
                return new TorqueRightInstruction(torque_force_, 30);
            } else if (last_instruction_ == TorqueLeft) {
                last_instruction_ = TorqueLeft;
                return new TorqueLeftInstruction(torque_force_, 30);
            }
            return new DeltaSpeedUpdateInstruction(-5);
        }
    }

    last_instruction_ = Other;
    if (current_car_state_.front_right_reflector_color_ == black) {
        last_time_on_black_ = millis();
        last_instruction_ = TorqueRight;
        return new TorqueRightInstruction(torque_force_ - 15, 30);
    }
    if (current_car_state_.front_left_reflector_color_ == black) {
        last_time_on_black_ = millis();
        last_instruction_ = TorqueLeft;
        return new TorqueLeftInstruction(torque_force_ - 15, 30);
    }
    if (current_car_state_.front_mid_reflector_color_ == black) {
        last_time_on_black_ = millis();
        return new ForceSpeedUpdateInstruction(base_speed_ - 15, base_speed_);
    }

    return new ForceSpeedUpdateInstruction(base_speed_, base_speed_);
}

#include "line_trace_brain.h"
#include "custom/instruction/torque_left_instruction.h"
#include "custom/instruction/torque_right_instruction.h"
#include "custom/instruction/force_speed_update_instruction.h"
#include "custom/instruction/force_stop_instruction.h"
#include "custom/instruction/wait_instruction.h"
#include "ArduinoLog.h"
#include "custom/instruction/update_direction_instruction.h"
#include "custom/instruction/delta_speed_update_instruction.h"
#include "core/data_model/binary_color.h"

#define THRESHOLD 10

int calc_weight(int prev, int current) {
    int value = current - prev;
    if (value > THRESHOLD) {
        value = THRESHOLD;
    } else if (value < -THRESHOLD) {
        value = -THRESHOLD;
    }
    return value;
}

Instruction *LineTraceBrain::CalculateNextInstruction() {
    // 準備中
    if (this->state_ == READY) {
        // 発進してライン探索モードに移行
        this->state_ = SEARCHING_LINE;
        return new ForceSpeedUpdateInstruction(run_speed_, run_speed_);
    }
    // ライン探索中
    if (this->state_ == SEARCHING_LINE) {
        // どれか一つのセンサーが黒になったらトレース開始・一旦停止
        if (current_car_state_.front_left_reflector_color == black || current_car_state_.front_mid_reflector_color == black ||
            current_car_state_.front_right_reflector_color == black) {
            trace_start_time_ = millis();
            state_ = TRACING_LINE;
            return new ForceStopInstruction();
        }
        return new wait_instruction(10);
    }
    // ライントレース中
    if (this->state_ == TRACING_LINE) {
        unsigned long current_time = millis();

        // スピードが0なら発進
        if (current_car_state_.left_wheel_speed == 0 || current_car_state_.right_wheel_speed == 0) {
            return new ForceSpeedUpdateInstruction(run_speed_, run_speed_);
        }

        // 全部黒のとき
//        if (current_car_state_.front_mid_reflector_color == black && current_car_state_.front_left_reflector_color == black &&
//            current_car_state_.front_right_reflector_color == black) {
//            return new ForceSpeedUpdateInstruction(run_speed_, run_speed_);
//        }

        // 全部白のとき
        if (current_car_state_.front_mid_reflector_color == white && current_car_state_.front_left_reflector_color == white &&
            current_car_state_.front_right_reflector_color == white) {
            if (current_time - trace_start_time_ > 1500) {
                state_ = READY_FOR_BACK;
                return new ForceStopInstruction();
            }
            return new DeltaSpeedUpdateInstruction(-5);
        }

        // 左が黒なら左へ曲がる
        if (current_car_state_.front_left_reflector_color == black) {
            trace_start_time_ = millis();
            return new TorqueLeftInstruction(torque_force_, 30);
        }
        // 右が黒なら右へ曲がる
        if (current_car_state_.front_right_reflector_color == black) {
            trace_start_time_ = millis();
            return new TorqueRightInstruction(torque_force_, 30);
        }
        // 真ん中が黒なら直進
        if (current_car_state_.front_mid_reflector_color == black) {
            trace_start_time_ = millis();
            return new ForceSpeedUpdateInstruction(run_speed_, run_speed_);
        }

        return new ForceSpeedUpdateInstruction(run_speed_, run_speed_);
    }
    if (this->state_ == READY_FOR_BACK) {
        trace_start_time_ = millis();
        this->state_ = SEARCHING_BACK_LINE;
        return new UpdateDirectionInstruction(backward);
    }
    if (this->state_ == SEARCHING_BACK_LINE) {
        if (current_car_state_.front_left_reflector_color == black || current_car_state_.front_mid_reflector_color == black ||
            current_car_state_.front_right_reflector_color == black) {
            trace_start_time_ = millis();
            state_ = TRACING_BACK_LINE;
            return new ForceStopInstruction();
        }
        return new ForceSpeedUpdateInstruction(run_speed_, run_speed_);
    }
    if (this->state_ == TRACING_BACK_LINE) {

        unsigned long current_time = millis();
        if (current_car_state_.left_wheel_speed == 0 || current_car_state_.right_wheel_speed == 0) {
            return new ForceSpeedUpdateInstruction(run_speed_, run_speed_);
        }

        if (current_car_state_.front_mid_reflector_color == white && current_car_state_.front_left_reflector_color == white &&
            current_car_state_.front_right_reflector_color == white) {
            if (current_time - trace_start_time_ > 1000) {
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
        if (current_car_state_.front_right_reflector_color == black) {
            trace_start_time_ = millis();
            last_instruction_ = TorqueRight;
            return new TorqueRightInstruction(torque_force_ - 15, 30);
        }
        if (current_car_state_.front_left_reflector_color == black) {
            trace_start_time_ = millis();
            last_instruction_ = TorqueLeft;
            return new TorqueLeftInstruction(torque_force_ - 15, 30);
        }
        if (current_car_state_.front_mid_reflector_color == black) {
            trace_start_time_ = millis();
            return new ForceSpeedUpdateInstruction(run_speed_ - 15, run_speed_);
        }

        return new ForceSpeedUpdateInstruction(run_speed_, run_speed_);
    }
    return new ForceStopInstruction();

}

LineTraceBrain::LineTraceBrain(int run_speed, int torque_force) {
    this->run_speed_ = run_speed;
    this->torque_force_ = torque_force;
}

void LineTraceBrain::SetCurrentCarState(LineTraceCarState car_state) {
    current_car_state_  = car_state;
}

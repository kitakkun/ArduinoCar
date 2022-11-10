#include "zigzag_line_trace_brain.h"
#include "control/instruction/implementation/torque_left_instruction.h"
#include "control/instruction/implementation/torque_right_instruction.h"
#include "control/instruction/implementation/force_speed_update_instruction.h"
#include "control/instruction/implementation/force_stop_instruction.h"
#include "control/instruction/implementation/WaitInstruction.h"
#include "ArduinoLog.h"
#include "control/instruction/implementation/update_direction_instruction.h"
#include "control/instruction/implementation/decelerate_instruction.h"
#include "control/instruction/implementation/accelerate_instruction.h"

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

Instruction *ZigZagLineTraceBrain::CalculateNextInstruction(CarState state) {
    CarState prev_state = prev_state_;
    this->prev_state_ = state;
    // 準備中
    if (this->state_ == READY) {
        // 発進してライン探索モードに移行
        this->state_ = SEARCHING_LINE;
        return new ForceSpeedUpdateInstruction(run_speed_, run_speed_);
    }
    // ライン探索中
    if (this->state_ == SEARCHING_LINE) {
        // どれか一つのセンサーが黒になったらトレース開始・一旦停止
        if (state.front_left_reflector_color == black || state.front_mid_reflector_color == black ||
            state.front_right_reflector_color == black) {
            trace_start_time_ = millis();
            state_ = TRACING_LINE;
            return new ForceStopInstruction();
        }
        return new WaitInstruction(10);
    }
    // ライントレース中
    if (this->state_ == TRACING_LINE) {
        unsigned long current_time = millis();

        // スピードが0なら発進
        if (state.left_wheel_speed == 0 || state.right_wheel_speed == 0) {
            return new ForceSpeedUpdateInstruction(run_speed_, run_speed_);
        }

        // 全部黒のとき
//        if (state.front_mid_reflector_color == black && state.front_left_reflector_color == black &&
//            state.front_right_reflector_color == black) {
//            return new ForceSpeedUpdateInstruction(run_speed_, run_speed_);
//        }

        // 全部白のとき
        if (state.front_mid_reflector_color == white && state.front_left_reflector_color == white &&
            state.front_right_reflector_color == white) {
            if (current_time - trace_start_time_ > 1500) {
                state_ = READY_FOR_BACK;
                return new ForceStopInstruction();
            }
            return new DecelerateInstruction(5);
        }

        // 左が黒なら左へ曲がる
        if (state.front_left_reflector_color == black) {
            trace_start_time_ = millis();
            return new TorqueLeftInstruction(torque_force_, 30);
        }
        // 右が黒なら右へ曲がる
        if (state.front_right_reflector_color == black) {
            trace_start_time_ = millis();
            return new TorqueRightInstruction(torque_force_, 30);
        }
        // 真ん中が黒なら直進
        if (state.front_mid_reflector_color == black) {
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
        if (state.front_left_reflector_color == black || state.front_mid_reflector_color == black ||
            state.front_right_reflector_color == black) {
            trace_start_time_ = millis();
            state_ = TRACING_BACK_LINE;
            return new ForceStopInstruction();
        }
        return new ForceSpeedUpdateInstruction(run_speed_, run_speed_);
    }
    if (this->state_ == TRACING_BACK_LINE) {

        unsigned long current_time = millis();
        if (state.left_wheel_speed == 0 || state.right_wheel_speed == 0) {
            return new ForceSpeedUpdateInstruction(run_speed_, run_speed_);
        }

        if (state.front_mid_reflector_color == white && state.front_left_reflector_color == white &&
            state.front_right_reflector_color == white) {
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
                return new DecelerateInstruction(5);
            }
        }

        last_instruction_ = Other;
        if (state.front_right_reflector_color == black) {
            trace_start_time_ = millis();
            last_instruction_ = TorqueRight;
            return new TorqueRightInstruction(torque_force_ - 15, 30);
        }
        if (state.front_left_reflector_color == black) {
            trace_start_time_ = millis();
            last_instruction_ = TorqueLeft;
            return new TorqueLeftInstruction(torque_force_ - 15, 30);
        }
        if (state.front_mid_reflector_color == black) {
            trace_start_time_ = millis();
            return new ForceSpeedUpdateInstruction(run_speed_ - 15, run_speed_);
        }

        return new ForceSpeedUpdateInstruction(run_speed_, run_speed_);
    }
    return new ForceStopInstruction();

}

ZigZagLineTraceBrain::ZigZagLineTraceBrain(int run_speed, int torque_force) {
    this->run_speed_ = run_speed;
    this->torque_force_ = torque_force;
}

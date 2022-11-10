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

Instruction *ZigZagLineTraceBrain::CalculateNextInstruction(CarState state) {
    if (this->state_ == READY) {
        this->state_ = SEARCHING_LINE;
        return new ForceSpeedUpdateInstruction(run_speed_, run_speed_);
    }
    if (this->state_ == SEARCHING_LINE) {
        if (state.left_reflector_color == black || state.mid_reflector_color == black || state.right_reflector_color == black) {
            trace_start_time_ = millis();
            state_ = TRACING_LINE;
            return new ForceStopInstruction();
        }
        return new WaitInstruction(10);
    }
    if (this->state_ == TRACING_LINE) {
        unsigned long current_time = millis();
        if (state.left_wheel_speed == 0 || state.right_wheel_speed == 0) {
            return new ForceSpeedUpdateInstruction(run_speed_, run_speed_);
        }

        if (state.mid_reflector_color == white && state.left_reflector_color == white && state.right_reflector_color == white) {
            if (current_time - trace_start_time_ > 1000) {
                state_ = READY_FOR_BACK;
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
        if (state.left_reflector_color == black) {
            trace_start_time_ = millis();
            last_instruction_ = TorqueLeft;
            return new TorqueLeftInstruction(torque_force_, 30);
        }
        if (state.right_reflector_color == black) {
            trace_start_time_ = millis();
            last_instruction_ = TorqueRight;
            return new TorqueRightInstruction(torque_force_, 30);
        }
        if (state.mid_reflector_color == black) {
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
        if (state.left_reflector_color == black || state.mid_reflector_color == black || state.right_reflector_color == black) {
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

        if (state.mid_reflector_color == white && state.left_reflector_color == white && state.right_reflector_color == white) {
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
        if (state.right_reflector_color == black) {
            trace_start_time_ = millis();
            last_instruction_ = TorqueRight;
            return new TorqueRightInstruction(torque_force_ - 15, 30);
        }
        if (state.left_reflector_color == black) {
            trace_start_time_ = millis();
            last_instruction_ = TorqueLeft;
            return new TorqueLeftInstruction(torque_force_ - 15, 30);
        }
        if (state.mid_reflector_color == black) {
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

#include "zigzag_line_trace_brain.h"
#include "../instruction/torque_left_instruction.h"
#include "../instruction/torque_right_instruction.h"
#include "../instruction/force_speed_update_instruction.h"
#include "control/instruction/empty_instruction.h"
#include "control/instruction/force_stop_instruction.h"

Instruction *ZigZagLineTraceBrain::CalculateNextInstruction(CarState state) {
    if (this->state_ == READY) {
        this->state_ = TRACING_LINE;
        return new EmptyInstruction();
    }
    if (this->state_ == TRACING_LINE) {
        if (state.lw_speed == 0 && state.rw_speed == 0) {
            return new ForceSpeedUpdateInstruction(run_speed_, run_speed_);
        }
        // ライン上にいる
        if (state.front_color == black) {
            if (state.left_color == black) {
                return new TorqueLeftInstruction(torque_force_);
            } else if (state.right_color == black) {
                return new TorqueRightInstruction(torque_force_);
            }
            return new ForceSpeedUpdateInstruction(run_speed_, run_speed_);
        }
        this->state_ = FINISHED;
        return new ForceStopInstruction();
    }
    return new EmptyInstruction();
}

ZigZagLineTraceBrain::ZigZagLineTraceBrain(int run_speed, int torque_force) {
    this->run_speed_ = run_speed;
    this->torque_force_ = torque_force;
}

#include "zigzag_line_trace_brain.h"
#include "../instruction/torque_left_instruction.h"
#include "../instruction/torque_right_instruction.h"
#include "../instruction/force_speed_update_instruction.h"

Instruction *ZigZagLineTraceBrain::CalculateNextInstruction(CarState state) {
    if (state.lw_speed == 0 && state.rw_speed == 0) {
        return new ForceSpeedUpdateInstruction(run_speed_, run_speed_);
    } else if (state.left_color == white) {
        return new TorqueRightInstruction(torque_force_);
    } else if (state.right_color == white){
        return new TorqueLeftInstruction(torque_force_);
    }
    return new ForceSpeedUpdateInstruction(run_speed_, run_speed_);
}

ZigZagLineTraceBrain::ZigZagLineTraceBrain(int run_speed, int torque_force) {
    this->run_speed_ = run_speed;
    this->torque_force_ = torque_force;
}

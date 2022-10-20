#include "zigzag_line_trace_brain.h"
#include "../instruction/torque_left_instruction.h"
#include "../instruction/torque_right_instruction.h"
#include "../instruction/force_speed_update_instruction.h"

Instruction *ZigZagLineTraceBrain::CalculateNextInstruction(CarState state) {
    if (state.left_color == white) {
        return new TorqueRightInstruction(10);
    } else if (state.right_color == white) {
        return new TorqueLeftInstruction(10);
    }
    return new ForceSpeedUpdateInstruction(50, 50);
}

ZigZagLineTraceBrain::ZigZagLineTraceBrain() = default;

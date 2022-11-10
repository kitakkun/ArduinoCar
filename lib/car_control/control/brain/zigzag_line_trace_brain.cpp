#include "zigzag_line_trace_brain.h"
#include "control/instruction/implementation/torque_left_instruction.h"
#include "control/instruction/implementation/torque_right_instruction.h"
#include "control/instruction/implementation/force_speed_update_instruction.h"
#include "control/instruction/implementation/force_stop_instruction.h"
#include "control/instruction/implementation/WaitInstruction.h"
#include "ArduinoLog.h"

Instruction *ZigZagLineTraceBrain::CalculateNextInstruction(CarState state) {
    if (this->state_ == READY) {
        this->state_ = TRACING_LINE;
        return new WaitInstruction(1000);
    }
    if (this->state_ == TRACING_LINE) {
        if (state.left_wheel_speed == 0 || state.right_wheel_speed == 0) {
            return new ForceSpeedUpdateInstruction(run_speed_, run_speed_);
        }

//        if (state.mid_reflector_color == black && state.left_reflector_color == black && state.right_reflector_color == black) {
//            state_ = READY_FOR_BACK;
//            return new ForceStopInstruction();
//        }

        if (state.left_reflector_color == black) {
            return new TorqueLeftInstruction(torque_force_, 30);
        }
        if (state.right_reflector_color == black) {
            return new TorqueRightInstruction(torque_force_, 30);
        }
        if (state.mid_reflector_color == black) {
            return new ForceSpeedUpdateInstruction(run_speed_, run_speed_);
        }

        return new ForceSpeedUpdateInstruction(run_speed_, run_speed_);
    }
    return new ForceStopInstruction();
}

ZigZagLineTraceBrain::ZigZagLineTraceBrain(int run_speed, int torque_force) {
    this->run_speed_ = run_speed;
    this->torque_force_ = torque_force;
}

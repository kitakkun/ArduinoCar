#include <HardwareSerial.h>
#include "zigzag_line_trace_brain.h"
#include "../instruction/torque_left_instruction.h"
#include "../instruction/torque_right_instruction.h"
#include "../instruction/force_speed_update_instruction.h"
#include "control/instruction/force_stop_instruction.h"
#include "control/instruction/wait_instruction.h"

Instruction *ZigZagLineTraceBrain::CalculateNextInstruction(CarState state) {
    if (this->state_ == READY) {
        Serial.println("READY");
        this->state_ = TRACING_LINE;
        return new WaitInstruction(1000);
    }
    if (this->state_ == TRACING_LINE) {
//        Serial.println("TRACING_LINE");
        if (state.lw_speed == 0 || state.rw_speed == 0) {
            return new ForceSpeedUpdateInstruction(run_speed_, run_speed_);
        }
        // ライン上にいる
        if (state.left_color == black) {
            Serial.println("TORQUE_LEFT");
            return new TorqueLeftInstruction(torque_force_);
        } else if (state.right_color == black) {
            Serial.println("TORQUE_RIGHT");
            return new TorqueRightInstruction(torque_force_);
        }

        if (state.left_color == white && state.right_color == white && state.front_color == white) {
//            this->state_ = FINISHED;
        }
        return new ForceSpeedUpdateInstruction(run_speed_, run_speed_);
    }
    Serial.println("FINISHED");
    return new ForceStopInstruction();
}

ZigZagLineTraceBrain::ZigZagLineTraceBrain(int run_speed, int torque_force) {
    this->run_speed_ = run_speed;
    this->torque_force_ = torque_force;
}

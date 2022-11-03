#include <HardwareSerial.h>
#include "pid_controller.h"
#include "control/instruction/implementation/torque_left_instruction.h"
#include "control/instruction/implementation/torque_right_instruction.h"
#include "control/instruction/implementation/force_speed_update_instruction.h"
#include "control/instruction/implementation/force_stop_instruction.h"
#include "control/instruction/implementation/wait_instruction.h"

#define DELTA_T 0.010
#define Kp      0.165
#define Ki      0.013
#define Kd      0.0007
#define Target_Value  30

Instruction *PidLineTraceBrain::CalculateNextInstruction(CarState state) {
    if (this->state_ == READY) {
        Serial.println("READY");
        this->state_ = TRACING_LINE;
        return new WaitInstruction(1000);
    }
    if (this->state_ == TRACING_LINE) {
//        Serial.println("TRACING_LINE");
        float pid_left = PID(state.left_reflecter_raw);
        float pid_right = PID(state.right_reflecter_raw);

        if (state.left_wheel_speed == 0 || state.right_wheel_speed == 0) {
            return new ForceSpeedUpdateInstruction(run_speed_, run_speed_);
        }

        // ライン上にいる
        /*if (state.left_reflector_color == black) {
            Serial.println("TORQUE_LEFT");
            return new TorqueLeftInstruction(torque_force_);
        } else if (state.right_reflector_color == black) {
            Serial.println("TORQUE_RIGHT");
            return new TorqueRightInstruction(torque_force_);
        }*/

        //ライン上にいるとき
        if (pid_left > pid_right) {
            Serial.println("TORQUE_LEFT");
            return new TorqueLeftInstruction(pid_left - pid_right);
        } else if (pid_left < pid_right) {
            Serial.println("TORQUE_RIGHT");
            return new TorqueRightInstruction(torque_force_);
        }*/


        if (state.left_reflector_color == white && state.right_reflector_color == white && state.mid_reflector_color == white) {
//            this->state_ = FINISHED;
        }
        return new ForceSpeedUpdateInstruction(run_speed_, run_speed_);
    }
    Serial.println("FINISHED");
    return new ForceStopInstruction();
}

PidLineTraceBrain::PidLineTraceBrain(int run_speed, int torque_force) {
    this->run_speed_ = run_speed;
    this->torque_force_ = torque_force;
}

float PID(signed short Senser_Value){   //右車輪のPID制御(右車輪とアルゴリズムは一緒)

   static signed long diff_R[2];
   static float integral_R;
   
   float p,i,d;

   diff_R[0] = diff_R[1]; 
   diff_R[1] = Senser_Value  - Target_Value; 
   integral_R  += ( diff_R[1] + diff_R[0])/ 2.0 * DELTA_T ; 

   p = KP * diff_R[1] ;
   i = KI * integral_R ;
   d = KD * ( diff_R[1] - diff_R[0] )/DELTA_T ; 

   return math_limit(p+i+d);
}

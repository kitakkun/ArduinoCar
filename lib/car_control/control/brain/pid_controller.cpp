#include <HardwareSerial.h>
#include "pid_controller.h"
#include "control/instruction/implementation/torque_left_instruction.h"
#include "control/instruction/implementation/torque_right_instruction.h"
#include "control/instruction/implementation/force_speed_update_instruction.h"
#include "control/instruction/implementation/force_stop_instruction.h"
#include "control/instruction/implementation/wait_instruction.h"

#define KP 0.005
#define KI 0.015
#define KD 0.00005
#define DELTA_T 0.010
#define Target_Value 50

PidLineTraceBrain::PID_left(signed short Senser_Value){   
   float p,i,d;

   diff_L[0] = diff_L[1]; 
   diff_L[1] = Senser_Value  - Target_Value; 
   integral_L  += ( diff_L[1] + diff_L[0])/ 2.0 * DELTA_T ; 

   p = KP * diff_L[1] ;
   i = KI * integral_L ;
   d = KD * ( diff_L[1] - diff_L[0] )/DELTA_T ; 

   return math_limit(p+i+d, -20, 20);
}

PidLineTraceBrain::PID_right(signed short Senser_Value){   
   float p,i,d;

   diff_R[0] = diff_R[1]; 
   diff_R[1] = Senser_Value  - Target_Value; 
   integral_R  += ( diff_R[1] + diff_R[0])/ 2.0 * DELTA_T ; 

   p = KP * diff_R[1] ;
   i = KI * integral_R ;
   d = KD * ( diff_R[1] - diff_R[0] )/DELTA_T ; 

   return math_limit(p+i+d, -20, 20);
}

Instruction *PidLineTraceBrain::CalculateNextInstruction(CarState state) {
    if (this->state_ == READY) {
        Serial.println("READY");
        if (state.left_reflector_color == black || state.right_reflector_color == black || state.mid_reflector_color == white){
            return new ForceStopInstruction();
        }
        this->state_ = TRACING_LINE;
    }
    if (this->state_ == TRACING_LINE) {
//      Serial.println("TRACING_LINE");
        int pid_left = PID_left(state.left_reflecter_raw);
        int pid_right = PID_right(state.right_reflecter_raw);

        if (state.left_wheel_speed == 0 || state.right_wheel_speed == 0) {
            return new ForceSpeedUpdateInstruction(run_speed_, run_speed_);
        }

        //ライン上にいるとき
        if (state.mid_reflector_color == black || state.left_reflector_color == black || state.right_reflector_color == black) {
            return new ForceSpeedUpdateInstruction(run_speed_ + pid_left - pid_right, run_speed_ - pid_left + pid_right);
        }
        if (state.left_reflector_color == white && state.right_reflector_color == white && state.mid_reflector_color == white) {
            //this->state_ = FINISHED;
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
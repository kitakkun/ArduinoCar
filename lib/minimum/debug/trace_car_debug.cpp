#include "trace_car_debug.h"

TraceCarDebugger::TracecarDebugger(TraceCar *trace_car){
    this->trace_car_ = trace_car;
}

//センサーの出力
void DebugSensors(){
    Serial.print(" LeftSensor= ");
    Serial.print(this->trace_car_->GetLeftReflector());
    Serial.print(" MidSensor= ");
    Serial.print(this->trace_car_->GetMidReflector());
    Serial.print(" RightSensor= ");
    Serial.println(this->trace_car_->GetRightReflector());
}

//モーターの出力
void DebugMotors(){
    Serial.print(" LeftMotor= ");
    Serial.print(this->trace_car_->GetLeftMotor());
    Serial.print(" RightMotor= ");
    Serial.println(this->trace_car_->GetRightMotor());
}

#include "trace_car_debugger.h"
#include <Arduino.h>

TraceCarDebugger::TraceCarDebugger(TraceCar *trace_car) {
    this->trace_car_ = trace_car;
}

//センサーの出力
void TraceCarDebugger::DebugSensors() {
    Serial.print(" LeftSensor= ");
    Serial.print(this->trace_car_->GetLeftReflector()->GetRawValue());
    Serial.print(" MidSensor= ");
    Serial.print(this->trace_car_->GetMidReflector()->GetRawValue());
    Serial.print(" RightSensor= ");
    Serial.println(this->trace_car_->GetRightReflector()->GetRawValue());
}

//モーターの出力
void TraceCarDebugger::DebugMotors() {
    Serial.print(" LeftMotor= ");
    Serial.print(this->trace_car_->GetLeftMotor()->GetSpeed());
    Serial.print(" RightMotor= ");
    Serial.println(this->trace_car_->GetRightMotor()->GetSpeed());
}

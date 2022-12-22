#include "follow_car_debug.h"
#include <Arduino.h>

FollowCarDebugger::FollowCarDebugger(FollowCar *follow_car){
    this->follow_car_ = follow_car;
}

//センサーの出力
void FollowCarDebugger::DebugSensors(){
    Serial.print(" LeftSensor= ");
    Serial.print(this->follow_car_->GetLeftSensor()->GetRawValue());
    Serial.print(" RightSensor= ");
    Serial.println(this->follow_car_->GetRightSensor()->GetRawValue());
}

//モーターの出力
void FollowCarDebugger::DebugMotors(){
    Serial.print(" LeftMotor= ");
    Serial.print(this->follow_car_->GetLeftMotor()->GetSpeed());
    Serial.print(" RightMotor= ");
    Serial.println(this->follow_car_->GetRightMotor()->GetSpeed());
}

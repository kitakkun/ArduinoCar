#include "follow_car_debug.h"

FollowCarDebugger::FollowcarDebugger(FollowCar *follow_car){
    this->follow_car_ = follow_car;
}

//センサーの出力
void DebugSensors(){
    Serial.print(" LeftSensor= ");
    Serial.print(this->follow_car_->GetLeftSensor());
    Serial.print(" RightSensor= ");
    Serial.println(this->follow_car_->GetRightSensor());
}

//モーターの出力
void DebugMotors(){
    Serial.print(" LeftMotor= ");
    Serial.print(this->follow_car_->GetLeftMotor());
    Serial.print(" RightMotor= ");
    Serial.println(this->follow_car_->GetRightMotor());
}

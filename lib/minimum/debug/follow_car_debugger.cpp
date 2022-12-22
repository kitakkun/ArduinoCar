#include "follow_car_debugger.h"
#include "ArduinoLog.h"
#include <Arduino.h>

FollowCarDebugger::FollowCarDebugger(FollowCar *follow_car) {
    this->follow_car_ = follow_car;
}

//センサーの出力
void FollowCarDebugger::DebugSensors() {
    Log.verboseln(
        "LeftSensor: %d, RightSensor: %d",
        this->follow_car_->GetLeftSensor()->GetRawValue(),
        this->follow_car_->GetRightSensor()->GetRawValue()
    );
}

//モーターの出力
void FollowCarDebugger::DebugMotors() {
    Log.verboseln(
        "LeftSpeed: %d, RightSpeed: %d",
        this->follow_car_->GetLeftMotor()->GetSpeed(),
        this->follow_car_->GetRightMotor()->GetSpeed()
    );
}

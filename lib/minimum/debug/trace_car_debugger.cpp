#include "trace_car_debugger.h"
#include "ArduinoLog.h"

TraceCarDebugger::TraceCarDebugger(TraceCar *trace_car) {
    this->trace_car_ = trace_car;
}

//センサーの出力
void TraceCarDebugger::DebugSensors() {
    Log.verboseln(
        "LeftSensor: %d, MidSensor: %d, RightSensor: %d",
        this->trace_car_->GetLeftReflector()->GetRawValue(),
        this->trace_car_->GetMidReflector()->GetRawValue(),
        this->trace_car_->GetRightReflector()->GetRawValue()
    );
}

//モーターの出力
void TraceCarDebugger::DebugMotors() {
    Log.verboseln(
        "LeftSpeed: %d, RightSpeed: %d",
        this->trace_car_->GetLeftMotor()->GetSpeed(),
        this->trace_car_->GetRightMotor()->GetSpeed()
    );
}

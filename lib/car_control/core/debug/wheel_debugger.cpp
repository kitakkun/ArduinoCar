#include "wheel_debugger.h"
#include "ArduinoLog.h"

void WheelDebugger::PrintDebugLog() {
    Log.verboseln(
            "[WheelDebugger] left_speed: %d, right_speed: %d, left_direction: %d, right_direction: %d",
            this->left_wheel_->Speed(),
            this->right_wheel_->Speed(),
            this->left_wheel_->Direction(),
            this->right_wheel_->Direction()
    );
}

WheelDebugger::WheelDebugger(Wheel *left_wheel, Wheel *right_wheel) {
    this->left_wheel_ = left_wheel;
    this->right_wheel_ = right_wheel;
}

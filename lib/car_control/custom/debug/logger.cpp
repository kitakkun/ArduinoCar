#include "logger.h"
#include "ArduinoLog.h"

void Logger::LogLineTraceCarState(LineTraceCarState car_state) {
    Log.verboseln("l_speed: %d, r_speed: %d", car_state.left_wheel_speed_, car_state.right_wheel_speed_);
    Log.verboseln("[front] mid: %d, left: %d, right: %d", car_state.front_mid_reflector_raw_,
                  car_state.front_left_reflector_raw_, car_state.front_right_reflector_raw_);
    Log.verboseln("[back]  mid: %d, left: %d, right: %d\n",
                  car_state.back_mid_reflector_raw_,
                  car_state.back_left_reflector_raw_,
                  car_state.back_right_reflector_raw_);
}

#include "logger.h"
#include "ArduinoLog.h"

void Logger::LogLineTraceCarState(LineTraceCarState car_state) {
    Log.verboseln(
            "l_speed    : %d\n"
            "w_speed    : %d\n"
            "front_mid  : %d\n"
            "front_left : %d\n"
            "front_right: %d\n"
            "back_mid  : %d\n"
            "back_left : %d\n"
            "back_right: %d\n",
            car_state.left_wheel_speed,
            car_state.right_wheel_speed,
            car_state.front_mid_reflector_raw,
            car_state.front_left_reflector_raw,
            car_state.front_right_reflector_raw,
            car_state.back_mid_reflector_raw,
            car_state.back_left_reflector_raw,
            car_state.back_right_reflector_raw
    );
}

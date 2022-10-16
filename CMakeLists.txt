cmake_minimum_required(VERSION 3.22)
project(Laboratory_Work_In_Information_Engineering_III)

set(CMAKE_CXX_STANDARD 14)

include(FetchContent)

FetchContent_Declare(
        ace_routine
        GIT_REPOSITORY https://github.com/bxparks/AceRoutine
        GIT_TAG v1.5.1
)

FetchContent_Declare(
        arduino_core_avr
        GIT_REPOSITORY https://github.com/arduino/ArduinoCore-avr
        GIT_TAG 1.8.5
)

FetchContent_MakeAvailable(arduino_core_avr)
FetchContent_MakeAvailable(ace_routine)

include_directories(src/control)
include_directories(cmake-build-debug/_deps/ace_routine-src/src)
include_directories(cmake-build-debug/_deps/ace_routine-src/src/ace_routine)
include_directories(cmake-build-debug/_deps/arduino_core_avr-src/cores/arduino)

add_library(
        car_control
        src/control/car.h
        src/control/photo_reflector.cpp
        src/control/photo_reflector.h
        src/control/move_direction.h
        src/control/paper_color.h
        src/control/sensor.cpp
        src/control/sensor.h
        src/control/wheel.cpp
        src/control/sample.ino
        src/control/wheel.h
        src/control/config.h
        src/control/car.cpp
        src/control/brain.cpp
        src/control/brain.h
        src/control/car_state.h
        src/control/car_builder.cpp
        src/control/car_builder.h
        src/control/ilne_trace_brain.cpp
        src/control/line_trace_brain.h
        src/control/instruction.h
        src/control/instruction.cpp
        src/control/instruction/accelerate_instruction.cpp
        src/control/instruction/accelerate_instruction.h
        src/control/instruction/decelerate_instruction.cpp src/control/instruction/decelerate_instruction.h)

target_link_libraries(car_control PRIVATE ace_routine_target)
target_link_libraries(car_control PRIVATE arduino_core_avr_target)

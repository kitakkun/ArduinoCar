#include <Arduino.h>
#include <core.h>
#include <custom.h>
#include "config.h"
#include "ArduinoLog.h"
#include "core/debug/wheel_debugger.h"
#include "core/debug/sensor_debugger.h"

Car *car;
Wheel *left_wheel;
Wheel *right_wheel;
LineTraceBrain *brain;
WheelDebugger *wheel_debugger;
SensorDebugger *sensor_debugger;
PhotoReflector *left_reflector;
PhotoReflector *right_reflector;
PhotoReflector *mid_reflector;

void setup() {
    Serial.begin(115200);
    while (!Serial);
    Log.begin(LOG_LEVEL_VERBOSE, &Serial, true);

    left_reflector = new PhotoReflectorImpl(LEFT_PHOTO_REFLECTOR_PIN, PHOTO_REFLECTOR_THRESHOLD, "Left");
    right_reflector = new PhotoReflectorImpl(RIGHT_PHOTO_REFLECTOR_PIN, PHOTO_REFLECTOR_THRESHOLD, "Right");
    mid_reflector = new PhotoReflectorImpl(MID_PHOTO_REFLECTOR_PIN, PHOTO_REFLECTOR_THRESHOLD, "Mid");
    left_wheel = new WheelImpl(LEFT_MOTOR_PLUS_PIN, LEFT_MOTOR_MINUS_PIN, LEFT_MOTOR_PWM_PIN);
    right_wheel = new WheelImpl(RIGHT_MOTOR_PLUS_PIN, RIGHT_MOTOR_MINUS_PIN, RIGHT_MOTOR_PWM_PIN, RIGHT_SPEED_GAIN);
    wheel_debugger = new WheelDebugger(left_wheel, right_wheel);
    sensor_debugger = new SensorDebugger(mid_reflector, left_reflector, right_reflector);
    brain = new PidLineTraceBrain(
            TRACE_MODE,
            BASE_SPEED,
            TURN_SPEED,
            P,
            D,
            LR_SENSOR_DIFF,
            MAX_MANIPULATION
    );
    car = LineTraceCarBuilder()
            .SetBrain(brain)
            .SetLeftWheel(left_wheel)
            .SetRightWheel(right_wheel)
            .SetMidReflector(mid_reflector)
            .SetRightReflector(right_reflector)
            .SetLeftReflector(left_reflector)
            .Build();
    Log.verboseln("Ready...");
}

void loop() {
    car->UpdateSensors();
    car->Think();
    car->Act();
//    wheel_debugger->PrintDebugLog();
//    sensor_debugger->PrintDebugLog();
    delay(5);
}
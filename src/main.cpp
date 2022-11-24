#include <Arduino.h>
#include <core.h>
#include <custom.h>
#include "config.h"
#include "ArduinoLog.h"

Car *car;
PhotoReflector *left_reflector;
PhotoReflector *right_reflector;
PhotoReflector *mid_reflector;

void setup() {
    Serial.begin(115200);
    while (!Serial);
    Log.begin(LOG_LEVEL_VERBOSE, &Serial, true);

    Log.verboseln("Building a Car instance...");
    left_reflector = new PhotoReflectorImpl(LEFT_PHOTO_REFLECTOR_PIN, PHOTO_REFLECTOR_THRESHOLD, "Left");
    right_reflector = new PhotoReflectorImpl(RIGHT_PHOTO_REFLECTOR_PIN, PHOTO_REFLECTOR_THRESHOLD, "Right");
    mid_reflector = new PhotoReflectorImpl(MID_PHOTO_REFLECTOR_PIN, PHOTO_REFLECTOR_THRESHOLD, "Mid");
    car = LineTraceCarBuilder()
            .SetBrain(new PidLineTraceBrain(TRACE_MODE, BASE_SPEED, TURN_SPEED, P, D, LR_SENSOR_DIFF, MAX_MANIPULATION))
            .SetLeftWheel(new WheelImpl(LEFT_MOTOR_PLUS_PIN, LEFT_MOTOR_MINUS_PIN, LEFT_MOTOR_PWM_PIN, "LeftWheel"))
            .SetRightWheel(new WheelImpl(RIGHT_MOTOR_PLUS_PIN, RIGHT_MOTOR_MINUS_PIN, RIGHT_MOTOR_PWM_PIN, "RightWheel"))
            .SetMidReflector(mid_reflector)
            .SetRightReflector(right_reflector)
            .SetLeftReflector(left_reflector)
            .Build();
    Log.verboseln("Done! Started Program Lifecycle.");
}

void loop() {
    car->UpdateSensors();
//    Log.verboseln("%d %d %d", left_reflector->RawValue(), right_reflector->RawValue(), left_reflector->RawValue() - right_reflector->RawValue());
    car->Think();
    car->Act();
    delay(10);
}
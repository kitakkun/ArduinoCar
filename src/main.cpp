#include <Arduino.h>
#include <core.h>
#include <custom.h>
#include "config.h"
#include "ArduinoLog.h"

Car *car;

void setup() {
    Serial.begin(115200);
    while (!Serial);
    Log.begin(LOG_LEVEL_VERBOSE, &Serial, true);

    Log.verboseln("Building a Car instance...");
    LineTraceCarBuilder builder = LineTraceCarBuilder();
    builder.SetBrain(new LineTraceGoAndBackBrain(105, 45));
    builder.SetLeftWheel(new WheelImpl(LEFT_MOTOR_PLUS_PIN, LEFT_MOTOR_MINUS_PIN, LEFT_MOTOR_PWM_PIN, "LeftWheel"));
    builder.SetRightWheel(new WheelImpl(RIGHT_MOTOR_PLUS_PIN, RIGHT_MOTOR_MINUS_PIN, RIGHT_MOTOR_PWM_PIN, "RightWheel"));
    builder.SetFrontMidReflector(new PhotoReflectorImpl(FRONT_MID_PHOTO_REFLECTOR_PIN, PHOTO_REFLECTOR_THRESHOLD, "FrontMid"));
    builder.SetFrontRightReflector(new PhotoReflectorImpl(FRONT_RIGHT_PHOTO_REFLECTOR_PIN, PHOTO_REFLECTOR_THRESHOLD, "FrontRight"));
    builder.SetFrontLeftReflector(new PhotoReflectorImpl(FRONT_LEFT_PHOTO_REFLECTOR_PIN, PHOTO_REFLECTOR_THRESHOLD, "FrontLeft"));
    builder.SetBackMidReflector(new PhotoReflectorImpl(BACK_MID_PHOTO_REFLECTOR_PIN, PHOTO_REFLECTOR_THRESHOLD, "BackMid"));
    builder.SetBackRightReflector(new PhotoReflectorImpl(BACK_RIGHT_PHOTO_REFLECTOR_PIN, PHOTO_REFLECTOR_THRESHOLD, "BackRight"));
    builder.SetBackLeftReflector(new PhotoReflectorImpl(BACK_LEFT_PHOTO_REFLECTOR_PIN, PHOTO_REFLECTOR_THRESHOLD, "BackLeft"));
    car = builder.Build();
    Log.verboseln("Done! Started Program Lifecycle.");

    delay(1000);
}

void loop() {
    car->UpdateSensors();
    car->Think();
    car->Act();
    delay(50);
}
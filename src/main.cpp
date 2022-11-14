#include <Arduino.h>
#include <core.h>
#include <custom.h>
#include "config.h"
#include "ArduinoLog.h"

Car *car;

void setup() {
    Serial.begin(115200);
    while (!Serial);
    Log.begin(LOG_LEVEL_VERBOSE, &Serial, false);

    Log.verboseln("Building a Car instance...");
    LineTraceCarBuilder builder = LineTraceCarBuilder();
    builder.SetBrain(new LineTraceBrain(105, 45));
    builder.SetLeftWheel(new Wheel(LEFT_MOTOR_PLUS_PIN, LEFT_MOTOR_MINUS_PIN, LEFT_MOTOR_PWM_PIN));
    builder.SetRightWheel(new Wheel(RIGHT_MOTOR_PLUS_PIN, RIGHT_MOTOR_MINUS_PIN, RIGHT_MOTOR_PWM_PIN));
    builder.SetFrontMidReflector(new PhotoReflector(FRONT_MID_PHOTO_REFLECTOR_PIN, PHOTO_REFLECTOR_THRESHOLD));
    builder.SetFrontRightReflector(new PhotoReflector(FRONT_RIGHT_PHOTO_REFLECTOR_PIN, PHOTO_REFLECTOR_THRESHOLD));
    builder.SetFrontLeftReflector(new PhotoReflector(FRONT_LEFT_PHOTO_REFLECTOR_PIN, PHOTO_REFLECTOR_THRESHOLD));
    builder.SetBackMidReflector(new PhotoReflector(BACK_MID_PHOTO_REFLECTOR_PIN, PHOTO_REFLECTOR_THRESHOLD));
    builder.SetBackRightReflector(new PhotoReflector(BACK_RIGHT_PHOTO_REFLECTOR_PIN, PHOTO_REFLECTOR_THRESHOLD));
    builder.SetBackLeftReflector(new PhotoReflector(BACK_LEFT_PHOTO_REFLECTOR_PIN, PHOTO_REFLECTOR_THRESHOLD));
    car = builder.Build();
    Log.verboseln("Done!");
}

void loop() {
    car->UpdateSensors();
    car->Think();
    car->Act();
}
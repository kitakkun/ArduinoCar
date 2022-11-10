#include <Arduino.h>
#include <car_control.h>
#include <config.h>
#include <ArduinoLog.h>
#include "control/brain/dummy_brain.h"

Car *car;

void setup() {
    Serial.begin(9600);
    Log.begin(LOG_LEVEL_VERBOSE, &Serial);

    PinConfigurator::Config();

    CarBuilder builder = CarBuilder();
    builder.SetBrain(new ZigZagLineTraceBrain(105, 45));
    builder.SetLeftWheel(new Wheel(LEFT_MOTOR_PLUS_PIN, LEFT_MOTOR_MINUS_PIN, LEFT_MOTOR_PWM_PIN));
    builder.SetRightWheel(new Wheel(RIGHT_MOTOR_PLUS_PIN, RIGHT_MOTOR_MINUS_PIN, RIGHT_MOTOR_PWM_PIN));
    builder.SetFrontMidReflector(new PhotoReflector(FRONT_MID_PHOTO_REFLECTOR_PIN, PHOTO_REFLECTOR_THRESHOLD));
    builder.SetFrontRightReflector(new PhotoReflector(FRONT_RIGHT_PHOTO_REFLECTOR_PIN, PHOTO_REFLECTOR_THRESHOLD));
    builder.SetFrontLeftReflector(new PhotoReflector(FRONT_LEFT_PHOTO_REFLECTOR_PIN, PHOTO_REFLECTOR_THRESHOLD));
    builder.SetBackMidReflector(new PhotoReflector(BACK_MID_PHOTO_REFLECTOR_PIN, PHOTO_REFLECTOR_THRESHOLD));
    builder.SetBackRightReflector(new PhotoReflector(BACK_RIGHT_PHOTO_REFLECTOR_PIN, PHOTO_REFLECTOR_THRESHOLD));
    builder.SetBackLeftReflector(new PhotoReflector(BACK_LEFT_PHOTO_REFLECTOR_PIN, PHOTO_REFLECTOR_THRESHOLD));
    car = builder.Build();
}

void loop() {
     car->UpdateSensors();
     CarState state = car->CollectCarState();
     Instruction *instruction = car->Think(state);
     car->SetInstruction(instruction);
     car->Act();
}
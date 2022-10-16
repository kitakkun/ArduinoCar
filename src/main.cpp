#include <Arduino.h>
#include "car_control.h"

Car *car;

void setup() {
    CarBuilder builder = CarBuilder();
    builder.SetLeftWheel(new Wheel(LEFT_MOTOR_PLUS_PIN, LEFT_MOTOR_MINUS_PIN, LEFT_MOTOR_PWM_PIN));
    builder.SetRightWheel(new Wheel(RIGHT_MOTOR_PLUS_PIN, RIGHT_MOTOR_MINUS_PIN, RIGHT_MOTOR_PWM_PIN));
    builder.SetFrontReflector(new PhotoReflector(FRONT_PHOTO_REFLECTOR_PIN, 10));
    builder.SetRightReflector( new PhotoReflector(RIGHT_PHOTO_REFLECTOR_PIN, 10));
    builder.SetLeftReflector(new PhotoReflector(LEFT_PHOTO_REFLECTOR_PIN, 10));
    car = builder.Build();

    Serial.begin(9600);
}

void loop() {
    // car->UpdateSensors();
    // CarState state = car->CollectCarState();
    // Instruction *instruction = car->Think(state);
    // car->SetInstruction(instruction);
    // car->Act();

    Serial.println("HELLO");
    delay(1000);
}
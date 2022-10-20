#include "pin_configurator.h"
#include "config.h"
#include <Arduino.h>

void PinConfigurator::Config() {
    pinMode(RIGHT_MOTOR_PLUS_PIN, OUTPUT);
    pinMode(RIGHT_MOTOR_MINUS_PIN, OUTPUT);
    pinMode(RIGHT_MOTOR_PWM_PIN, OUTPUT);

    pinMode(LEFT_MOTOR_PLUS_PIN, OUTPUT);
    pinMode(LEFT_MOTOR_MINUS_PIN, OUTPUT);
    pinMode(LEFT_MOTOR_PWM_PIN, OUTPUT);

    pinMode(RIGHT_PHOTO_REFLECTOR_PIN, INPUT);
    pinMode(FRONT_PHOTO_REFLECTOR_PIN, INPUT);
    pinMode(LEFT_PHOTO_REFLECTOR_PIN, INPUT);
}

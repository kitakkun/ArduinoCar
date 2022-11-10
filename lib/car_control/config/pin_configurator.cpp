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

    pinMode(FRONT_RIGHT_PHOTO_REFLECTOR_PIN, INPUT);
    pinMode(FRONT_MID_PHOTO_REFLECTOR_PIN, INPUT);
    pinMode(FRONT_LEFT_PHOTO_REFLECTOR_PIN, INPUT);

    pinMode(BACK_RIGHT_PHOTO_REFLECTOR_PIN, INPUT);
    pinMode(BACK_MID_PHOTO_REFLECTOR_PIN, INPUT);
    pinMode(BACK_LEFT_PHOTO_REFLECTOR_PIN, INPUT);
}

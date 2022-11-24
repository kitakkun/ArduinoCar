#ifndef CONFIG_H
#define CONFIG_H

#include <Arduino.h>

#define BASE_SPEED 70
#define LR_SENSOR_DIFF -4
#define TURN_SPEED 110
#define TRACE_MODE continuous
#define P 0.058
#define D 0.010
#define MAX_MANIPULATION 22

#define RIGHT_SPEED_GAIN 20

#define RIGHT_MOTOR_PLUS_PIN 2
#define RIGHT_MOTOR_MINUS_PIN 3
#define RIGHT_MOTOR_PWM_PIN 10

#define LEFT_MOTOR_PLUS_PIN 4
#define LEFT_MOTOR_MINUS_PIN 5
#define LEFT_MOTOR_PWM_PIN 11

#define RIGHT_PHOTO_REFLECTOR_PIN A0
#define MID_PHOTO_REFLECTOR_PIN A1
#define LEFT_PHOTO_REFLECTOR_PIN A2

#define PHOTO_REFLECTOR_THRESHOLD 50

#endif //CONFIG_H

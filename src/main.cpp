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
    car = LineTraceCarBuilder()
            .SetBrain(new LineTraceGoAndBackBrain(BASE_SPEED, FORWARD_TORQUE, BACKWARD_TORQUE))
            .SetLeftWheel(new WheelImpl(LEFT_MOTOR_PLUS_PIN, LEFT_MOTOR_MINUS_PIN, LEFT_MOTOR_PWM_PIN, "LeftWheel"))
            .SetRightWheel(new WheelImpl(RIGHT_MOTOR_PLUS_PIN, RIGHT_MOTOR_MINUS_PIN, RIGHT_MOTOR_PWM_PIN, "RightWheel"))
            .SetMidReflector(new PhotoReflectorImpl(MID_PHOTO_REFLECTOR_PIN, PHOTO_REFLECTOR_THRESHOLD, "Mid"))
            .SetRightReflector(new PhotoReflectorImpl(RIGHT_PHOTO_REFLECTOR_PIN, PHOTO_REFLECTOR_THRESHOLD, "Right"))
            .SetLeftReflector(new PhotoReflectorImpl(LEFT_PHOTO_REFLECTOR_PIN, PHOTO_REFLECTOR_THRESHOLD, "Left"))
            .Build();
    Log.verboseln("Done! Started Program Lifecycle.");

    delay(1000);
}

void loop() {
    car->UpdateSensors();
    car->Think();
    car->Act();
}
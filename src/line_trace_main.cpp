#include <Arduino.h>
#include "trace_car.h"
#include "car_controller.h"
#include "controller/pid_trace_controller.h"
#include "ArduinoLog.h"

CarController *controller;

const int delay_millis = 10;
const int reflector_theta = 500;

void setup() {
    Serial.begin(115200);
    while (!Serial);
    Log.begin(LOG_LEVEL_VERBOSE, &Serial, true);
    Log.verboseln("Building a Car instance...");
    auto *car = new TraceCar(
            new Motor(4, 5, 11),
            new Motor(2, 3, 10),
            new PhotoReflector(A1, reflector_theta),
            new PhotoReflector(A2, reflector_theta),
            new PhotoReflector(A0, reflector_theta)
    );

    car->GetLeftMotor()->UpdateDirection(forward);
    car->GetRightMotor()->UpdateDirection(forward);

    controller = new PidTraceController(
            car,
            120, 
            -4,
            80,
            0.052,
            0.042
    );
}

void loop() {
    controller->Update();
    controller->Operate();
    delay(delay_millis);
}
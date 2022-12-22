#include <Arduino.h>
#include "follow_car.h"
#include "car_controller.h"
#include "controller/pid_follow_controller.h"
#include "ArduinoLog.h"

CarController *controller;

const int delay_millis = 10;

void setup() {
    Serial.begin(115200);
    while (!Serial);
    Log.begin(LOG_LEVEL_VERBOSE, &Serial, true);
    Log.verboseln("Building a Car instance...");
    auto *car = new FollowCar(
            new Motor(2, 3, 10),
            new Motor(4, 5, 11),
            new SonicSensor(pin0, pin3),    // TODO:pin番号を入力する
            new SonicSensor(pin1, pin4),
            new SonicSensor(pin2, pin5)
    );

    car->GetLeftMotor()->UpdateDirection(forward);
    car->GetRightMotor()->UpdateDirection(forward);

    controller = new PidFollowController(
            car,
            100,
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
#include <Arduino.h>
#include "follow_car.h"
#include "car_controller.h"
#include "controller/pid_follow_controller.h"
#include "ArduinoLog.h"
#include "motor_impl.h"
#include "sonic_sensor_impl.h"

CarController *controller;

const int delay_millis = 10;

void setup() {
    Serial.begin(115200);
    while (!Serial);
    Log.begin(LOG_LEVEL_VERBOSE, &Serial, true);
    Log.verboseln("Building a Car instance...");
    auto *car = new FollowCar(
            new MotorImpl(2, 3, 10),
            new MotorImpl(4, 5, 11),
            new SonicSensorImpl(pin0, pin3),    // TODO:pin番号を入力する
            new SonicSensorImpl(pin1, pin4),
            new SonicSensorImpl(pin2, pin5)
    );

    car->GetLeftMotor()->UpdateDirection(forward);
    car->GetRightMotor()->UpdateDirection(forward);

    controller = new PidFollowController(
            car,
            5,
            100,
            -4,
            80,
            20,
            0.052,
            0.05,
            0.042,
            0.05
    );
}

void loop() {

    controller->Update();
    controller->Operate();
    delay(delay_millis);
}
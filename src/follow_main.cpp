#include <Arduino.h>
#include "car/follow_car.h"
#include "interface/car_controller.h"
#include "controller/pid_follow_controller.h"
#include "ArduinoLog.h"
#include "impl.h"
#include "debug/follow_car_debugger.h"

CarController *controller;
FollowCarDebugger *debugger;
const int delay_millis = 10;

void setup() {
    Serial.begin(115200);
    while (!Serial);
    Log.begin(LOG_LEVEL_VERBOSE, &Serial, true);
    Log.verboseln("Building a Car instance...");
    FollowCar *car = new FollowCar(
        new MotorImpl(2, 3, 11),
        new MotorImpl(4, 5, 10),
        new SonicSensorImpl(6, 7),    // TODO:pin番号を入力する
        new SonicSensorImpl(9, 8)
    );

    debugger = new FollowCarDebugger(car);

    car->GetLeftMotor()->UpdateDirection(forward);
    car->GetRightMotor()->UpdateDirection(forward);

    controller = new PidFollowController(
        car,
        7.5,
        105,
        0,
        20,
        50,
        0.50,
        0.50,
        10.0,
        6.0
    );
}

void loop() {
    controller->Update();
    controller->Operate();
    delay(delay_millis);
    debugger->DebugSensors();
    //Serial.println(car->GetLeftSensor()->GetRawValue());
    // Serial.println(car->GetLeftSensor()->GetRawValue());
}
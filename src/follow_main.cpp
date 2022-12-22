#include <Arduino.h>
#include "car/follow_car.h"
#include "interface/car_controller.h"
#include "controller/pid_follow_controller.h"
#include "ArduinoLog.h"
#include "impl.h"
#include "carbuilder/follow_car_builder.h"
#include "controllerbuilder/pid_follow_controller_builder.h"

CarController *controller;

const int delay_millis = 10;

void setup() {
    Serial.begin(115200);
    while (!Serial);
    Log.begin(LOG_LEVEL_VERBOSE, &Serial, true);
    Log.verboseln("Building a Car instance...");
    auto *car = FollowCarBuilder()
        .SetLeftMotor(new MotorImpl(2, 3, 10))
        .SetRightMotor(new MotorImpl(4, 5, 11))
        .SetLeftSensor(new SonicSensorImpl(A0, A0))
        .SetRightSensor(new SonicSensorImpl(A0, A0))
        .Build();

    car->GetLeftMotor()->UpdateDirection(forward);
    car->GetRightMotor()->UpdateDirection(forward);

    controller = PidFollowControllerBuilder()
        .SetCar(car)
        .SetBaseDistance(5)
        .SetBaseSpeed(100)
        .SetLRSensorDiff(-4)
        .SetDistanceMaxManipulation(80)
        .SetTorqueMaxManipulation(20)
        .SetDistancePWeight(0.052)
        .SetDistanceDWeight(0.05)
        .SetTorquePWeight(0.042)
        .SetTorqueDWeight(0.05)
        .Build();
}

void loop() {
    controller->Update();
    controller->Operate();
    delay(delay_millis);
}
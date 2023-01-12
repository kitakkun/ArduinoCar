#include <Arduino.h>
#include "car/follow_car.h"
#include "interface/car_controller.h"
#include "ArduinoLog.h"
#include "impl.h"
#include "debug/follow_car_debugger.h"
#include "carbuilder/follow_car_builder.h"
#include "controllerbuilder/pid_follow_controller_builder.h"

CarController *controller;
FollowCarDebugger *debugger;
HeartbeatLedImpl *heartbeatLed;

const int delay_millis = 10;

void setup() {
    Serial.begin(115200);
    while (!Serial);
    Log.begin(LOG_LEVEL_VERBOSE, &Serial, true);
    Log.verboseln("Building a Car instance...");
    auto *car = FollowCarBuilder()
        .SetLeftMotor(new MotorImpl(2, 3, 11))
        .SetRightMotor(new MotorImpl(4, 5, 10))
        .SetLeftSensor(new SonicSensorImpl(6, 7))
        .SetRightSensor(new SonicSensorImpl(9, 8))
        .SetCrashDetector(new DigitalSensorImpl(12))
        .Build();

    debugger = new FollowCarDebugger(car);

    controller = PidFollowControllerBuilder()
        .SetCar(car)
        .SetBaseDistance(10.0)
        .SetBaseSpeed(130)
        .SetLRSensorDiff(0)
        .SetDistanceMaxManipulation(20)
        .SetTorqueMaxManipulation(50)
        .SetDistancePWeight(15.0)
        .SetDistanceDWeight(10.0)
        .SetTorquePWeight(12.0)
        .SetTorqueDWeight(7.0)
        .Build();

    heartbeatLed = new HeartbeatLedImpl(13, 500);
}

void loop() {
    controller->Update();
    controller->Operate();
    heartbeatLed->runCoroutine();
    delay(delay_millis);
    // debugger->DebugSensors();
    //Serial.println(car->GetLeftSensor()->GetRawValue());
    // Serial.println(car->GetLeftSensor()->GetRawValue());
}
#include <Arduino.h>
#include "interface/car_controller.h"
#include "ArduinoLog.h"
#include "impl.h"
#include "debug/follow_car_debugger.h"
#include "carbuilder/follow_car_builder.h"
#include "controller/follow/pid_follow_controller_builder.h"

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
        .SetBaseDistance(6.0)
        .SetBaseSpeed(130)
        .SetLRSensorDiff(0.1)
        .SetDistanceMaxManipulation(70)
        .SetTorqueMaxManipulation(50)
        .SetSpeedPidController(new PIDController(10.0, 0.0, 8.0))
        .SetTorquePidController(new PIDController(12.0, 0.0, 9.0))
        .Build();

    heartbeatLed = new HeartbeatLedImpl(13, 500);
}

void loop() {
    controller->Update();
    controller->Operate();
    heartbeatLed->runCoroutine();
    delay(delay_millis);
    debugger->DebugSensors();
    //Serial.println(car->GetLeftSensor()->GetRawValue());
    // Serial.println(car->GetLeftSensor()->GetRawValue());
}
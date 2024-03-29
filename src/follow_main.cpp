#include <Arduino.h>
#include "interface/car_controller.h"
#include "ArduinoLog.h"
#include "impl.h"
#include "debug/follow/follow_car_debugger.h"
#include "car/follow/follow_car_builder.h"
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
        .SetLeftSensor(new SonicSensorImpl(6, 7, 0, 20))
        .SetRightSensor(new SonicSensorImpl(9, 8, 0, 20))
        .SetCrashDetector(new DigitalSensorImpl(12))
        .Build();

    debugger = new FollowCarDebugger(car);

    controller = PidFollowControllerBuilder()
        .SetCar(car)
        .SetBaseDistance(6.0)
        .SetBaseSpeed(130)
        .SetLRSensorDiff(0.1)
        .SetDistanceMaxManipulation(25)
        .SetTorqueMaxManipulation(40)
        .SetSpeedPidController(new PIDController(10.0, 0.5, 8.0))
        .SetTorquePidController(new PIDController(11.0, 2.0, 8.0))
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
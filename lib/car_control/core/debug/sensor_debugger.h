#ifndef LABORATORY_WORK_IN_INFORMATION_ENGINEERING_III_SENSOR_DEBUGGER_H
#define LABORATORY_WORK_IN_INFORMATION_ENGINEERING_III_SENSOR_DEBUGGER_H


#include "core/component/sensor.h"
#include "debugger.h"

class SensorDebugger : public Debugger {
public:
    SensorDebugger(Sensor* mid_sensor, Sensor *left_sensor, Sensor *right_sensor);
    void PrintDebugLog() override;

private:
    Sensor* mid_sensor_;
    Sensor* left_sensor_;
    Sensor* right_sensor_;
};


#endif //LABORATORY_WORK_IN_INFORMATION_ENGINEERING_III_SENSOR_DEBUGGER_H

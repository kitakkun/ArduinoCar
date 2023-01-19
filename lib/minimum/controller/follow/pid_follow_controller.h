#ifndef LABORATORY_WORK_IN_INFORMATION_ENGINEERING_III_PID_FOLLOW_CONTROLLER_H
#define LABORATORY_WORK_IN_INFORMATION_ENGINEERING_III_PID_FOLLOW_CONTROLLER_H


#include "interface/car_controller.h"
#include "car/follow/follow_car.h"
#include "impl/sonic_sensor_updater.h"
#include "pid_controller.h"
#include "datamodel/follow_params.h"

class PidFollowController : public CarController {
public:
    explicit PidFollowController(
        FollowCar *car,
        PIDController *speed_pid_controller,
        PIDController *torque_pid_controller,
        FollowParams params
    );

    void Update() override;

    void Operate() override;

protected:
    FollowCar *car_;
    SonicSensorUpdater *sensor_updater_;
    PIDController *speed_pid_controller_;
    PIDController *torque_pid_controller_;
    FollowParams params_;

    virtual void Follow();
};


#endif //LABORATORY_WORK_IN_INFORMATION_ENGINEERING_III_PID_FOLLOW_CONTROLLER_H
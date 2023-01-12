#ifndef LABORATORY_WORK_IN_INFORMATION_ENGINEERING_III_PID_FOLLOW_CONTROLLER_BUILDER_H
#define LABORATORY_WORK_IN_INFORMATION_ENGINEERING_III_PID_FOLLOW_CONTROLLER_BUILDER_H

#include "car/follow_car.h"
#include "controller/pid_follow_controller.h"
#include "controller/pid_controller.h"

class PidFollowControllerBuilder {
public:
    PidFollowControllerBuilder &SetCar(FollowCar *car);

    PidFollowControllerBuilder &SetBaseDistance(float base_distance);

    PidFollowControllerBuilder &SetBaseSpeed(int base_speed);

    PidFollowControllerBuilder &SetLRSensorDiff(float lr_sensor_diff);

    PidFollowControllerBuilder &SetDistanceMaxManipulation(int max_manipulation_dist);

    PidFollowControllerBuilder &SetTorqueMaxManipulation(int max_manipulation_torque);

    PidFollowControllerBuilder &SetSpeedPidController(PIDController *pid_controller);

    PidFollowControllerBuilder &SetTorquePidController(PIDController *pid_controller);

    PidFollowController *Build();

private:
    FollowCar *car_;
    PIDController *speed_pid_controller_;
    PIDController *torque_pid_controller_;
    float base_distance_;
    int base_speed_;
    float lr_sensor_diff_;
    int max_manipulation_dist_;
    int max_manipulation_torque_;
};


#endif //LABORATORY_WORK_IN_INFORMATION_ENGINEERING_III_PID_FOLLOW_CONTROLLER_BUILDER_H

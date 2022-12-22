#ifndef LABORATORY_WORK_IN_INFORMATION_ENGINEERING_III_PID_FOLLOW_CONTROLLER_BUILDER_H
#define LABORATORY_WORK_IN_INFORMATION_ENGINEERING_III_PID_FOLLOW_CONTROLLER_BUILDER_H

#include "car/follow_car.h"
#include "controller/pid_follow_controller.h"

class PidFollowControllerBuilder {
public:
    PidFollowControllerBuilder &SetCar(FollowCar *car);

    PidFollowControllerBuilder &SetBaseDistance(int base_distance);

    PidFollowControllerBuilder &SetBaseSpeed(int base_speed);

    PidFollowControllerBuilder &SetLRSensorDiff(int lr_sensor_diff);

    PidFollowControllerBuilder &SetDistanceMaxManipulation(int max_manipulation_dist);

    PidFollowControllerBuilder &SetTorqueMaxManipulation(int max_manipulation_torque);

    PidFollowControllerBuilder &SetDistancePWeight(float p_weight_dist);

    PidFollowControllerBuilder &SetDistanceDWeight(float d_weight_dist);

    PidFollowControllerBuilder &SetTorquePWeight(float p_weight_torque);

    PidFollowControllerBuilder &SetTorqueDWeight(float d_weight_torque);

    PidFollowController *Build();

private:
    FollowCar *car_;
    int base_distance_;
    int base_speed_;
    int lr_sensor_diff_;
    int max_manipulation_dist_;
    int max_manipulation_torque_;
    float p_weight_dist_;
    float d_weight_dist_;
    float p_weight_torque_;
    float d_weight_torque_;
};


#endif //LABORATORY_WORK_IN_INFORMATION_ENGINEERING_III_PID_FOLLOW_CONTROLLER_H

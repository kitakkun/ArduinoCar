#ifndef LABORATORY_WORK_IN_INFORMATION_ENGINEERING_III_PID_FOLLOW_CONTROLLER_H
#define LABORATORY_WORK_IN_INFORMATION_ENGINEERING_III_PID_FOLLOW_CONTROLLER_H


#include "interface/car_controller.h"
#include "car/follow_car.h"
#include "sonic_sensor_updater.h"
#include "pid_controller.h"

class PidFollowController : public CarController {
public:
    PidFollowController(
        FollowCar *car,
        float base_distance,
        int base_speed,
        float lr_sensor_diff,
        int max_manipulation_dist,
        int max_manipulation_torque,
        float p_weight_dist,
        float d_weight_dist,
        float p_weight_torque,
        float d_weight_torque
    );

    PidFollowController(
        FollowCar *car,
        float base_distance,
        int base_speed,
        float lr_sensor_diff,
        int max_manipulation_dist,
        int max_manipulation_torque,
        PIDController *speed_pid_controller,
        PIDController *torque_pid_controller
    );

    void Update() override;

    void Operate() override;

protected:
    FollowCar *car_;
    SonicSensorUpdater *sensor_updater_;
    PIDController *speed_pid_controller_;
    PIDController *torque_pid_controller_;
    float base_distance_;
    int base_speed_;
    float lr_sensor_diff_; // 左右のセンサの個体差
    int max_manipulation_dist_;
    int max_manipulation_torque_;

    virtual void Follow();
};


#endif //LABORATORY_WORK_IN_INFORMATION_ENGINEERING_III_PID_FOLLOW_CONTROLLER_H
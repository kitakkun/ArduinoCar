#ifndef LABORATORY_WORK_IN_INFORMATION_ENGINEERING_III_PID_FOLLOW_CONTROLLER_H
#define LABORATORY_WORK_IN_INFORMATION_ENGINEERING_III_PID_FOLLOW_CONTROLLER_H


#include "interface/car_controller.h"
#include "car/follow_car.h"
#include "sonic_sensor_updater.h"

class PidFollowController : public CarController {
public:
    explicit PidFollowController(
        FollowCar *car,
        float base_distance,
        float min_distance,
        int base_speed,
        int ir_sensor_diff,
        int max_manipulation_dist,
        int max_manipulation_torque,
        float p_weight_dist,
        float d_weight_dist,
        float p_weight_torque,
        float d_weight_torque
    );

    void Update() override;

    void Operate() override;

protected:
    FollowCar *car_;
    SonicSensorUpdater *sensor_updater_;
    float base_distance_;
    float min_distance_;
    int base_speed_;
    int lr_sensor_diff_; // 左右のセンサの個体差
    int max_manipulation_dist_;
    int max_manipulation_torque_;
    float p_weight_dist_;
    float d_weight_dist_;
    float p_weight_torque_;
    float d_weight_torque_;
    unsigned long last_time_called_;

    virtual void Follow();

private:
    float prev_distance_;
    float prev_deviation_;
};


#endif //LABORATORY_WORK_IN_INFORMATION_ENGINEERING_III_PID_FOLLOW_CONTROLLER_H
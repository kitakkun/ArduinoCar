#ifndef LABORATORY_WORK_IN_INFORMATION_ENGINEERING_III_PID_FOLLOW_CONTROLLER_H
#define LABORATORY_WORK_IN_INFORMATION_ENGINEERING_III_PID_FOLLOW_CONTROLLER_H


#include "car_controller.h"
#include "follow_car.h"

class PidFollowController : public CarController {
public:
    explicit PidFollowController(
        FollowCar *car,
        int theta,
        int base_speed,
        int ir_sensor_diff,
        int max_manipulation_dist,
        int max_manipulation_dev,
        float p_weight_dist,
        float d_weight_dist,
        float p_weight_dev,
        float d_weight_dev
    );

    void Operate() override;

protected:
    FollowCar *car_;
    int theta_;
    int base_speed_;
    int lr_sensor_diff_; // 左右のセンサの個体差
    int max_manipulation_dist_;
    int max_manipulation_dev_;
    float p_weight_dist_;
    float d_weight_dist_;
    float p_weight_dev_;
    float d_weight_dev_;
    unsigned long last_time_called_;

    virtual void Follow();

private:
    float prev_distance_;
    float prev_deviation_;
};


#endif //LABORATORY_WORK_IN_INFORMATION_ENGINEERING_III_PID_FOLLOW_CONTROLLER_H
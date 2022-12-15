#ifndef LABORATORY_WORK_IN_INFORMATION_ENGINEERING_III_PID_FOLLOW_CONTROLLER_H
#define LABORATORY_WORK_IN_INFORMATION_ENGINEERING_III_PID_FOLLOW_CONTROLLER_H


#include "car_controller.h"
#include "follow_car.h"

class PidFollowController : public CarController {
Public:
    explicit PidFollowController(
        FollowCar *car,
        int base_speed,
        int ir_sensor_diff,
        int max_manipulation,
        float p_weight,
        float d_weight
    );

    void Operate() override;

protected:
    FollowCar *car_;
    int base_speed_;
    int lr_sensor_diff_; // 左右のセンサの個体差
    int max_manipulation_;
    float p_weight_;
    float d_weight_;
    unsigned long last_time_called_;

    virtual void Follow();

private:
    float prev_deviation_;
};


#endif //LABORATORY_WORK_IN_INFORMATION_ENGINEERING_III_PID_FOLLOW_CONTROLLER_H
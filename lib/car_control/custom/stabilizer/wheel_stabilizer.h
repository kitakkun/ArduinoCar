#ifndef WHEEL_STABILIZER_H
#define WHEEL_STABILIZER_H

#include "core/component/wheel.h"

class WheelStabilizer{
public:
    explicit WheelStabilizer(int min_speed, int max_speed); 
    void Stabilize (Wheel *left_wheel, Wheel *right_wheel);
private:
    int min_speed_; //　最小のスピード
    int max_speed_; //  最大のスピード
};

#endif //WHEELSTABILIZER

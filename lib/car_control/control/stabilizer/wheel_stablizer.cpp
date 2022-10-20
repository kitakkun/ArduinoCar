# include "wheel_stabilizer.h"

void WheelStablizer::Stablize(Wheel *left_wheel,Wheel *right_wheel){
    if(left_wheel->Speed() < min_speed_) left_wheel->UpdateSpeed(min_speed_);
    if(left_wheel->Speed() > max_speed_) left_wheel->UpdateSpeed(max_speed_);
    if(right_wheel->Speed() < min_speed_) right_wheel->UpdateSpeed(min_speed_);
    if(right_wheel->Speed() > max_speed_) right_wheel->UpdateSpeed(max_speed_);     
}

WheelStabilizer::WheelStabilizer(int min_speed, int max_speed){
    this->min_speed_ = min_speed;
    this->max_speed_ = max_speed;
}

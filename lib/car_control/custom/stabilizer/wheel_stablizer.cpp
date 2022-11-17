# include "wheel_stabilizer.h"

void WheelStabilizer::Stabilize(WheelImpl *left_wheel, WheelImpl *right_wheel){
    if(left_wheel->Speed() < this->min_speed_) left_wheel->UpdateSpeed(this->min_speed_);
    if(left_wheel->Speed() > this->max_speed_) left_wheel->UpdateSpeed(this->max_speed_);
    if(right_wheel->Speed() < this->min_speed_) right_wheel->UpdateSpeed(this->min_speed_);
    if(right_wheel->Speed() > this->max_speed_) right_wheel->UpdateSpeed(this->max_speed_);     
}

WheelStabilizer::WheelStabilizer(int min_speed, int max_speed){
    this->min_speed_ = min_speed;
    this->max_speed_ = max_speed;
}

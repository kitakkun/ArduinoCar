#include "sonic_sensor_update_scheduler.h"

SonicSensorUpdateScheduler::SonicSensorUpdateScheduler(SonicSensor *left_sensor, SonicSensor *right_sensor) {
    this->left_sensor_ = left_sensor;
    this->right_sensor_ = right_sensor;
    updating_sensor_ = this->left_sensor_;
}

void SonicSensorUpdateScheduler::Update() {
    this->updating_sensor_->Update();
    if(this->updating_sensor_->IsUpdateCompleted()) {
        if (this->updating_sensor_ == this->left_sensor_) {
            this->updating_sensor_ = this->right_sensor_;
        } else {
            this->updating_sensor_ = this->left_sensor_;
        }
        this->updating_sensor_->InitUpdateTask();
    }
}

#include "sonic_sensor_updater.h"

SonicSensorUpdater::SonicSensorUpdater(SonicSensor *left_sensor, SonicSensor *right_sensor) {
    this->left_sensor_ = left_sensor;
    this->right_sensor_ = right_sensor;
    updating_sensor_ = this->left_sensor_;
}

void SonicSensorUpdater::Update() {
    bool is_update_completed = this->updating_sensor_->Update();
    if (!is_update_completed) return;
    if (updating_sensor_ == left_sensor_)
        updating_sensor_ = right_sensor_;
    else
        updating_sensor_ = left_sensor_;
}

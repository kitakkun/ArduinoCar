#include "pid_trace_controller.h"
#include <Arduino.h>

PidTraceController::PidTraceController(
        TraceCar *car,
        int base_speed,
        int lr_sensor_diff,
        int max_manipulation,
        float p_weight,
        float d_weight
) {
    this->car_ = car;
    this->base_speed_ = base_speed;
    this->lr_sensor_diff_ = lr_sensor_diff;
    this->max_manipulation_ = max_manipulation;
    this->p_weight_ = p_weight;
    this->d_weight_ = d_weight;
}

void PidTraceController::Operate() {
    int deviation = this->car_->GetLeftReflector()->GetRawValue()
                    - this->car_->GetRightReflector()->GetRawValue()
                    - this->lr_sensor_diff_;

    unsigned long delta_time = millis() - last_time_called_;
    float deviation_differential = (float) (deviation - this->prev_deviation_) / (float) delta_time;

    int manipulation = (int) (this->p_weight_ * deviation + d_weight_ * deviation_differential);

    manipulation = constrain(manipulation, -this->max_manipulation_, this->max_manipulation_);

    this->prev_deviation_ = deviation;
    this->last_time_called_ = millis();

    this->car_->GetLeftMotor()->UpdateSpeed(this->base_speed_ - manipulation);
    this->car_->GetRightMotor()->UpdateSpeed(this->base_speed_ + manipulation);
}

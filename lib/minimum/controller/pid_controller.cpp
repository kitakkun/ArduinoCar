#include <Arduino.h>
#include "pid_controller.h"

PIDController::PIDController(double p_weight, double i_weight, double d_weight) {
    this->p_weight_ = p_weight;
    this->i_weight_ = i_weight;
    this->d_weight_ = d_weight;
    for (double &error: errors_) {
        error = 0.0;
    }
    this->error_cursor_ = 0;
}

// actual を target に近づけるための操作量を返す
double PIDController::CalcManipulation(double actual, double target) {

    double deviation = actual - target;

    unsigned long delta_time = millis() - last_time_called_;
    double deviation_differential = (deviation - this->prev_deviation_) / (double) delta_time;

    double error_sum = 0.0;
    for (double &error: errors_) {
        error_sum += error;
    }

    double manipulation = this->p_weight_ * deviation +
                          this->i_weight_ * error_sum +
                          this->d_weight_ * deviation_differential;

    this->prev_deviation_ = deviation;
    this->last_time_called_ = millis();
    this->errors_[this->error_cursor_] = deviation;
    this->error_cursor_++;
    this->error_cursor_ %= 10;

    return manipulation;
}

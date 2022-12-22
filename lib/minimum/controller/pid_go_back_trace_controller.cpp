#include <Arduino.h>
#include "pid_go_back_trace_controller.h"

PidGoBackTraceController::PidGoBackTraceController(
    TraceCar *car, int base_speed,
    int lr_sensor_diff,
    int max_manipulation,
    float p_weight,
    float d_weight
) : PidTraceController(
    car,
    base_speed,
    lr_sensor_diff,
    max_manipulation,
    p_weight,
    d_weight
) {}

void PidGoBackTraceController::Operate() {
    switch (this->state_) {
        case ready:
            Ready();
            break;
        case searching:
            Search();
            break;
        case tracing:
            Trace();
            break;
        case readyBack:
            ReadyBack();
            break;
        case searchingBack:
            SearchBack();
            break;
        case tracingBack:
            TraceBack();
            break;
        case completed:
            Completed();
            break;
    }
}

void PidGoBackTraceController::Ready() {
    this->car_->GetLeftMotor()->UpdateSpeed(0);
    this->car_->GetRightMotor()->UpdateSpeed(0);
    this->car_->GetLeftMotor()->UpdateDirection(forward);
    this->car_->GetRightMotor()->UpdateSpeed(forward);
    this->UpdateState(searching);
}

void PidGoBackTraceController::Search() {
    if (this->car_->GetMidReflector()->IsBlack() ||
        this->car_->GetLeftReflector()->IsBlack() ||
        this->car_->GetRightReflector()->IsBlack()) {
        this->last_time_called_ = millis();
        this->UpdateState(tracing);
    } else {
        this->car_->GetLeftMotor()->UpdateSpeed(this->base_speed_);
        this->car_->GetRightMotor()->UpdateSpeed(this->base_speed_);
    }
}

void PidGoBackTraceController::Trace() {
    if (this->car_->GetMidReflector()->IsWhite() &&
        this->car_->GetLeftReflector()->IsWhite() &&
        this->car_->GetRightReflector()->IsWhite()) {
        this->UpdateState(readyBack);
    }
    PidTraceController::Trace();
}

void PidGoBackTraceController::ReadyBack() {
    this->car_->GetLeftMotor()->UpdateSpeed(0);
    this->car_->GetRightMotor()->UpdateSpeed(0);
    this->car_->GetLeftMotor()->UpdateDirection(backward);
    this->car_->GetRightMotor()->UpdateSpeed(backward);
    this->UpdateState(searchingBack);
}

void PidGoBackTraceController::SearchBack() {
    if (this->car_->GetMidReflector()->IsBlack() ||
        this->car_->GetLeftReflector()->IsBlack() ||
        this->car_->GetRightReflector()->IsBlack()) {
        this->last_time_called_ = millis();
        this->UpdateState(tracing);
    } else {
        this->car_->GetLeftMotor()->UpdateSpeed(this->base_speed_);
        this->car_->GetRightMotor()->UpdateSpeed(this->base_speed_);
    }
}

void PidGoBackTraceController::TraceBack() {
    if (this->car_->GetMidReflector()->IsWhite() &&
        this->car_->GetLeftReflector()->IsWhite() &&
        this->car_->GetRightReflector()->IsWhite()) {
        this->UpdateState(completed);
    }
    PidTraceController::Trace();
}

void PidGoBackTraceController::Completed() {
    this->car_->GetLeftMotor()->UpdateSpeed(0);
    this->car_->GetRightMotor()->UpdateSpeed(0);
    this->car_->GetLeftMotor()->UpdateDirection(forward);
    this->car_->GetRightMotor()->UpdateSpeed(forward);
}

void PidGoBackTraceController::UpdateState(TraceState new_state) {
    this->state_ = new_state;
}

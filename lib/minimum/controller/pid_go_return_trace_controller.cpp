#include "pid_go_return_trace_controller.h"
#include <Arduino.h>

PidGoReturnTraceController::PidGoReturnTraceController(
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

void PidGoReturnTraceController::Operate() {
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

void PidGoReturnTraceController::Ready() {
    this->car_->GetLeftMotor()->UpdateSpeed(0);
    this->car_->GetRightMotor()->UpdateSpeed(0);
    this->car_->GetLeftMotor()->UpdateDirection(forward);
    this->car_->GetRightMotor()->UpdateSpeed(forward);
    this->UpdateState(searching);
}

void PidGoReturnTraceController::Search() {
    if (this->car_->GetMidReflector()->IsBlack() ||
        this->car_->GetLeftReflector()->IsBlack() ||
        this->car_->GetRightReflector()->IsBlack()) {
        this->last_time_called_ = millis();   // 値が初期化された状態で次の状態に遷移したい
        this->UpdateState(tracing);
    } else {
        this->car_->GetLeftMotor()->UpdateSpeed(this->base_speed_);
        this->car_->GetRightMotor()->UpdateSpeed(this->base_speed_);
    }
}

void PidGoReturnTraceController::Trace() {
    if (this->car_->GetMidReflector()->IsWhite() &&
        this->car_->GetLeftReflector()->IsWhite() &&
        this->car_->GetRightReflector()->IsWhite()) {
        this->UpdateState(readyBack);
    }
    PidTraceController::Trace();
}

void PidGoReturnTraceController::ReadyBack() {
    this->car_->GetLeftMotor()->UpdateSpeed(0);
    this->car_->GetRightMotor()->UpdateSpeed(0);
    this->car_->GetLeftMotor()->UpdateDirection(backward);
    this->car_->GetRightMotor()->UpdateSpeed(backward);
    this->UpdateState(searchingBack);
}

void PidGoReturnTraceController::SearchBack() {
    if (this->car_->GetMidReflector()->IsBlack()) {
        /* TODO: 多分これだと一瞬のノイズの影響を受けて正確に遷移しない */
        this->last_time_called_ = millis();
        this->UpdateState(tracing);
    } else {
        this->car_->GetLeftMotor()->UpdateSpeed(this->base_speed_);
        this->car_->GetRightMotor()->UpdateSpeed(-this->base_speed_);
    }
}

void PidGoReturnTraceController::TraceBack() {
    if (this->car_->GetMidReflector()->IsWhite() &&
        this->car_->GetLeftReflector()->IsWhite() &&
        this->car_->GetRightReflector()->IsWhite()) {
        this->UpdateState(completed);
    }
    PidTraceController::Trace();
}

void PidGoReturnTraceController::Completed() {
    this->car_->GetLeftMotor()->UpdateSpeed(0);
    this->car_->GetRightMotor()->UpdateSpeed(0);
    this->car_->GetLeftMotor()->UpdateDirection(forward);
    this->car_->GetRightMotor()->UpdateSpeed(forward);
}

void PidGoReturnTraceController::UpdateState(TraceState new_state) {
    this->state_ = new_state;
}

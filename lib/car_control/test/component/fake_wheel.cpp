#include "fake_wheel.h"

FakeWheel::FakeWheel() {
    this->speed_ = 0;
    this->direction_ = forward;
}

void FakeWheel::UpdateSpeed(int speed) {
    this->speed_ = speed;
}

void FakeWheel::UpdateDeltaSpeed(int delta_speed) {
    this->speed_ += delta_speed;
}

void FakeWheel::UpdateDirection(MoveDirection direction) {
    this->direction_ = direction;
}

MoveDirection FakeWheel::Direction() {
    return direction_;
}

int FakeWheel::Speed() {
    return speed_;
}

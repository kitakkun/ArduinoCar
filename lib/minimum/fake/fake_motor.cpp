#include "fake_motor.h"

FakeMotor::FakeMotor() {
    this->speed_ = 0;
    this->direction_ = forward;
}

void FakeMotor::UpdateSpeed(int speed) {
    this->speed_ = speed;
}

void FakeMotor::UpdateDirection(MoveDirection direction) {
    this->direction_ = direction;
}

int FakeMotor::GetSpeed() {
    return this->speed_;
}

MoveDirection FakeMotor::GetMoveDirection() {
    return this->direction_;
}

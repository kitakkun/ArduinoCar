#include "instruction_impl.h"
#include "core/debug/logger.h"

void InstructionImpl::Setup(Wheel *left_wheel, Wheel *right_wheel) {
    this->left_wheel_ = left_wheel;
    this->right_wheel_ = right_wheel;
    this->mode_ = none;
}

InstructionMode InstructionImpl::Mode() {
    return this->mode_;
}

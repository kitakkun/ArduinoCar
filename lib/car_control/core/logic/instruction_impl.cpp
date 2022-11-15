#include "instruction_impl.h"
#include "core/debug/logger.h"

void InstructionImpl::Setup(Wheel *left_wheel, Wheel *right_wheel) {
    this->left_wheel_ = left_wheel;
    this->right_wheel_ = right_wheel;
}

InstructionMode InstructionImpl::Mode() {
    return this->mode_;
}

InstructionImpl::InstructionImpl(InstructionMode mode, String tag) : Debuggable(tag) {
    this->mode_ = mode;
}

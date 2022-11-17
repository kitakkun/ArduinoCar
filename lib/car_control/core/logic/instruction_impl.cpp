#include "instruction_impl.h"
#include "core/debug/logger.h"

void InstructionImpl::Setup(Wheel *left_wheel, Wheel *right_wheel) {
    this->left_wheel_ = left_wheel;
    this->right_wheel_ = right_wheel;
    Logger::Verboseln(this, F("Setup"));
}

InstructionMode InstructionImpl::Mode() {
    return this->mode_;
}

InstructionImpl::InstructionImpl(InstructionMode mode, String tag) : Debuggable(tag) {
    this->left_wheel_ = nullptr;
    this->right_wheel_ = nullptr;
    this->mode_ = mode;
    Logger::Verboseln(this, F("Instantiated"));
}

InstructionImpl::~InstructionImpl() {
    Logger::Verboseln(this, F("Deleted"));
}

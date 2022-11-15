#include "instruction.h"
#include "core/debug/logger.h"

Instruction::Instruction(InstructionMode mode, String tag) : Debuggable(tag, true) {
    this->mode_ = mode;
    this->left_wheel_ = nullptr;
    this->right_wheel_ = nullptr;
}

void Instruction::Setup(WheelImpl *left_wheel, WheelImpl *right_wheel) {
    this->left_wheel_ = left_wheel;
    this->right_wheel_ = right_wheel;
    Logger::Verboseln(this, F("Setup..."));
}

InstructionMode Instruction::Mode() {
    return this->mode_;
}

void Instruction::SetMode(InstructionMode mode) {
    this->mode_ = mode;
}

Instruction::~Instruction() {
    Logger::Verboseln(this, F("Deleted"));
}


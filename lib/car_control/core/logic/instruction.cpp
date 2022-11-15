#include "instruction.h"
#include "core/debug/logger.h"

Instruction::Instruction(InstructionMode mode, String tag) : Debuggable(tag) {
    this->mode_ = mode;
    this->left_wheel_ = nullptr;
    this->right_wheel_ = nullptr;
    Logger::Warningln(this, "Instantiated");
}

void Instruction::Setup(Wheel *left_wheel, Wheel *right_wheel) {
    this->left_wheel_ = left_wheel;
    this->right_wheel_ = right_wheel;
}

InstructionMode Instruction::Mode() {
    return this->mode_;
}

void Instruction::SetMode(InstructionMode mode) {
    this->mode_ = mode;
}

Instruction::~Instruction() {
    Logger::Warningln(this, "Deleted");
}


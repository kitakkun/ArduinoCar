#include "instruction.h"

Instruction::Instruction(InstructionMode mode) {
    this->mode_ = mode;
    this->left_wheel_ = nullptr;
    this->right_wheel_ = nullptr;
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

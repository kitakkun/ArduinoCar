#include "instruction.h"

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

#include "update_direction_instruction.h"

UpdateDirectionInstruction::UpdateDirectionInstruction(MoveDirection direction, InstructionMode mode) {
    this->direction_ = direction;
    this->mode_ = mode;
}

int UpdateDirectionInstruction::Run(Wheel *left_wheel, Wheel *right_wheel) {
    COROUTINE_BEGIN();
    left_wheel->UpdateDirection(direction_);
    right_wheel->UpdateDirection(direction_);
    COROUTINE_END();
}

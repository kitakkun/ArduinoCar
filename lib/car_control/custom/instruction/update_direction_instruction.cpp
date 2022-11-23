#include "update_direction_instruction.h"

UpdateDirectionInstruction::UpdateDirectionInstruction(MoveDirection direction, InstructionMode mode, String tag) {
    direction_ = direction;
}

int UpdateDirectionInstruction::Run(Wheel *left_wheel, Wheel *right_wheel) {
    COROUTINE_BEGIN();
    left_wheel->UpdateDirection(direction_);
    right_wheel->UpdateDirection(direction_);
    COROUTINE_END();
}

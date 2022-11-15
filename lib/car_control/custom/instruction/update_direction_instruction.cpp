#include "update_direction_instruction.h"

UpdateDirectionInstruction::UpdateDirectionInstruction(MoveDirection direction, InstructionMode mode, String tag)
        : Instruction(mode, tag) {
    direction_ = direction;
}

int UpdateDirectionInstruction::runCoroutine() {
    COROUTINE_BEGIN();
    left_wheel_->UpdateDirection(direction_);
    right_wheel_->UpdateDirection(direction_);
    COROUTINE_END();
}

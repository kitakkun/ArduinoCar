#include "update_direction_instruction.h"

UpdateDirectionInstruction::UpdateDirectionInstruction(MoveDirection direction) {
    direction_ = direction;
}

int UpdateDirectionInstruction::runCoroutine() {
    COROUTINE_BEGIN();
    left_wheel_->UpdateDirection(direction_);
    right_wheel_->UpdateDirection(direction_);
    left_wheel_->Apply();
    right_wheel_->Apply();
    COROUTINE_END();
}

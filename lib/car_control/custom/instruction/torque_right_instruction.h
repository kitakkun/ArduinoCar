#ifndef TORQUE_RIGHT_INSTRUCTION_H
#define TORQUE_RIGHT_INSTRUCTION_H

#include "core/logic/instruction_impl.h"

/**
 * 右へ曲がる指令
 */
class TorqueRightInstruction : public InstructionImpl {
public:
    explicit TorqueRightInstruction(
            int base_speed, int force, InstructionMode mode = none, String tag = "TorqueRightInstruction"
    );

    int runCoroutine() override;

private:
    int base_speed_;
    int force_;     /// 加えるトルクの強さ
    int duration_millis_;     /// トルクを加える時間
};

#endif //TORQUE_RIGHT_INSTRUCTION_H

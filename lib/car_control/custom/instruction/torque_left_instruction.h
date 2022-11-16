#ifndef TORQUE_LEFT_INSTRUCTION_H
#define TORQUE_LEFT_INSTRUCTION_H

#include "core/logic/instruction_impl.h"

/**
 * 左に曲がる指令
 */
class TorqueLeftInstruction : public InstructionImpl {
public:
    explicit TorqueLeftInstruction(
            int base_speed, int force, InstructionMode mode = none, String tag = "TorqueLeftInstruction"
    );

    int runCoroutine() override;

private:
    int base_speed_;
    int force_;     /// 加えるトルクの強さ
    int duration_millis_;     /// トルクを加える時間
};

#endif //TORQUE_LEFT_INSTRUCTION_H

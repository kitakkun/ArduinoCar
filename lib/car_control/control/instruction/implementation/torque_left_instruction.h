#ifndef TORQUE_LEFT_INSTRUCTION_H
#define TORQUE_LEFT_INSTRUCTION_H

#include "control/instruction/instruction.h"

/**
 * 左に曲がる指令
 */
class TorqueLeftInstruction : public Instruction {
public:
    explicit TorqueLeftInstruction(int force, int duration_millis);
    int runCoroutine() override;
private:
    int force_;     /// 加えるトルクの強さ
    int duration_millis_;
    int current_time_ = 0;
};

#endif //TORQUE_LEFT_INSTRUCTION_H

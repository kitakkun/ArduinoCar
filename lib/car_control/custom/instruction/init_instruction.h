#ifndef LABORATORY_WORK_IN_INFORMATION_ENGINEERING_III_INIT_INSTRUCTION_H
#define LABORATORY_WORK_IN_INFORMATION_ENGINEERING_III_INIT_INSTRUCTION_H


#include "core/logic/instruction.h"

/**
 * タイヤの状態を任意の速度・方向で初期化
 */
class InitInstruction : public Instruction {
public:
    InitInstruction(int left_speed, int right_speed, MoveDirection left_direction, MoveDirection right_direction, InstructionMode mode);

    int Run(Wheel *left_wheel, Wheel *right_wheel) override;
private:
    int left_speed_;
    int right_speed_;
    MoveDirection left_direction_;
    MoveDirection right_direction_;
};


#endif //LABORATORY_WORK_IN_INFORMATION_ENGINEERING_III_INIT_INSTRUCTION_H

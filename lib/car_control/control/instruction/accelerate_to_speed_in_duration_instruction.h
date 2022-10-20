#ifndef ACCELERATE_TO_SPEED_INSTRUCTION_H
#define ACCELERATE_TO_SPEED_INSTRUCTION_H

#include "instruction.h"

/**
 * 一定時間かけて目的の速度へ加速する指令
 */
class AccelerateToSpeedInDurationInstruction : public Instruction {
public:
    explicit AccelerateToSpeedInDurationInstruction(int target_speed, int duration_millis);

    void Run(Wheel *left_wheel, Wheel *right_wheel) override;

    bool InterruptionEnabled() override;

private:
    int target_speed_;      /// 目標速度
    int duration_millis_;   /// 目標速度になるまでの時間（ミリ秒）
};

#endif //ACCELERATE_TO_SPEED_INSTRUCTION_H

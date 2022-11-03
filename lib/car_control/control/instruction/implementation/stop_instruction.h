#ifndef STOP_INSTRUCTION_H
#define STOP_INSTRUCTION_H

#include "control/instruction/instruction.h"
#include <Arduino.h>

/**
 * 一定時間かけて減速，停止する指令
 @deprecated とりあえず使わない方針で。無限ループに入る恐れあり。
 */
class StopInstruction : public Instruction {
public:
    explicit StopInstruction(int duration_millis);
    int runCoroutine() override;

private:
    int speed_;    /// 現在のスピード
    int amount_;    /// 減速量
    int duration_millis_;   /// 停止するまでの時間（ミリ秒）
    int start_left_speed_;
    int start_right_speed_;
    int left_unit_decelerate_amount_;
    int right_unit_decelerate_amount_;
};

#endif //STOP_INSTRUCTION_H
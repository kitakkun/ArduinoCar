#ifndef STOP_INSTRUCTION_H
#define STOP_INSTRUCTION_H

#include "control/instruction/instruction.h"
#include <Arduino.h>

/**
 * 一定時間かけて減速，停止する指令
 */
class StopInstruction : public Instruction {
public:
    explicit StopInstruction(int duration_millis);

    void Run(Wheel *left_wheel, Wheel *right_wheel) override;

private:
    int speed_;    /// 現在のスピード
    int amount_;    /// 減速量
    int duration_millis_;   /// 停止するまでの時間（ミリ秒）
};

#endif //STOP_INSTRUCTION_H
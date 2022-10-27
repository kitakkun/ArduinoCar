#ifndef LABORATORY_WORK_IN_INFORMATION_ENGINEERING_III_WAIT_INSTRUCTION_H
#define LABORATORY_WORK_IN_INFORMATION_ENGINEERING_III_WAIT_INSTRUCTION_H

#include "instruction.h"
#include <Arduino.h>

class WaitInstruction : public Instruction {
public:
    explicit WaitInstruction(int wait_millis);
    void Run(Wheel *left_wheel, Wheel *right_wheel) override;
private:
    int wait_millis_;
};

WaitInstruction::WaitInstruction(int wait_millis) {
    this->wait_millis_ = wait_millis;
}

void WaitInstruction::Run(Wheel *left_wheel, Wheel *right_wheel) {
    delay(wait_millis_);
}

#endif //LABORATORY_WORK_IN_INFORMATION_ENGINEERING_III_WAIT_INSTRUCTION_H

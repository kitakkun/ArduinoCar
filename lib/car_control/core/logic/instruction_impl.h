#ifndef INSTRUCTION_H
#define INSTRUCTION_H

#include "core/component/wheel_impl.h"
#include "ace_routine/Coroutine.h"
#include "instruction_mode.h"
#include "core/debug/debuggable.h"
#include "instruction.h"

class InstructionImpl : public Instruction {
public:
    void Setup(Wheel *left_wheel, Wheel *right_wheel) override;

    InstructionMode Mode() override;

protected:
    Wheel *left_wheel_;
    Wheel *right_wheel_;
    InstructionMode mode_;
};

#endif //INSTRUCTION_H

#ifndef FORCE_STOP_INSTRUCTION
#define FORCE_STOP_INSTRUCTION


#include "update_speed_instruction.h"

class StopInstruction : public UpdateSpeedInstruction {
public:
    explicit StopInstruction(InstructionMode mode = none);
};

#endif //FORCE_STOP_INSTRUCTION
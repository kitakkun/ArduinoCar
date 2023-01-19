#ifndef LABORATORY_WORK_IN_INFORMATION_ENGINEERING_III_LED_IMPL_H
#define LABORATORY_WORK_IN_INFORMATION_ENGINEERING_III_LED_IMPL_H

#include "interface/led.h"

class LedImpl : public Led {
public:
    explicit LedImpl(int pin);

    void TurnOn() override;

    void TurnOff() override;

    void Toggle() override;

    bool IsOn() override;

private:
    int pin_;
    bool is_on_;

    void Apply();
};


#endif //LABORATORY_WORK_IN_INFORMATION_ENGINEERING_III_LED_IMPL_H

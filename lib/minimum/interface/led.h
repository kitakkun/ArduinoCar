#ifndef LABORATORY_WORK_IN_INFORMATION_ENGINEERING_III_LED_H
#define LABORATORY_WORK_IN_INFORMATION_ENGINEERING_III_LED_H

class Led {
public:
    virtual void TurnOn() = 0;

    virtual void TurnOff() = 0;

    virtual void Toggle() = 0;

    virtual bool IsOn() = 0;
};

#endif //LABORATORY_WORK_IN_INFORMATION_ENGINEERING_III_LED_H

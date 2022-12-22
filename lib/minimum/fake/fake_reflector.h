#ifndef LABORATORY_WORK_IN_INFORMATION_ENGINEERING_III_FAKE_REFLECTOR_H
#define LABORATORY_WORK_IN_INFORMATION_ENGINEERING_III_FAKE_REFLECTOR_H


#include "photo_reflector.h"
#include "fake_sensor.h"

class FakeReflector : public FakeSensor, public PhotoReflector {
public:
    explicit FakeReflector(int theta);

    int GetRawValue() override;

    void Update() override;

    bool IsBlack() override;

    bool IsWhite() override;

private:
    int theta_;
};


#endif //LABORATORY_WORK_IN_INFORMATION_ENGINEERING_III_FAKE_REFLECTOR_H

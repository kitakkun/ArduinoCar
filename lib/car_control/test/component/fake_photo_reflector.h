#ifndef LABORATORY_WORK_IN_INFORMATION_ENGINEERING_III_FAKE_PHOTO_REFLECTOR_H
#define LABORATORY_WORK_IN_INFORMATION_ENGINEERING_III_FAKE_PHOTO_REFLECTOR_H


#include "core/component/photo_reflector.h"

class FakePhotoReflector : public PhotoReflector {
public:
    explicit FakePhotoReflector(int theta_);
    void Update() override;
    BinaryColor Value() override;
    int RawValue() override;
    void SetRawValue(int raw_value);
private:
    int theta_;
    int raw_value_;
    BinaryColor value_;
};


#endif //LABORATORY_WORK_IN_INFORMATION_ENGINEERING_III_FAKE_PHOTO_REFLECTOR_H

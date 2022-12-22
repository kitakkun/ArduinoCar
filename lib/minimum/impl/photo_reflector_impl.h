#ifndef LABORATORY_WORK_IN_INFORMATION_ENGINEERING_III_PHOTO_REFLECTOR_IMPL_H
#define LABORATORY_WORK_IN_INFORMATION_ENGINEERING_III_PHOTO_REFLECTOR_IMPL_H

#include "sensor_impl.h"
#include "interface/photo_reflector.h"

class PhotoReflectorImpl : public SensorImpl, public PhotoReflector {
public:
    explicit PhotoReflectorImpl(int pin, int theta);

    int GetRawValue() override;

    void Update() override;

    bool IsBlack() override;

    bool IsWhite() override;

private:
    int theta_;
    bool is_black_;
};

#endif //LABORATORY_WORK_IN_INFORMATION_ENGINEERING_III_PHOTO_REFLECTOR_IMPL_H

#ifndef LABORATORY_WORK_IN_INFORMATION_ENGINEERING_III_LINETRACECAR_H
#define LABORATORY_WORK_IN_INFORMATION_ENGINEERING_III_LINETRACECAR_H

#include "interface/motor.h"
#include "interface/photo_reflector.h"

/**
 * ライントレース車の各コンポーネントへのアクセスを提供するクラス
 */
class TraceCar {
public:
    explicit TraceCar(
        Motor *left_motor,
        Motor *right_motor,
        PhotoReflector *mid_reflector,
        PhotoReflector *left_reflector,
        PhotoReflector *right_reflector
    );

    Motor *GetLeftMotor();

    Motor *GetRightMotor();

    PhotoReflector *GetMidReflector();

    PhotoReflector *GetLeftReflector();

    PhotoReflector *GetRightReflector();

private:
    Motor *left_motor_;
    Motor *right_motor_;
    PhotoReflector *mid_reflector_;
    PhotoReflector *left_reflector_;
    PhotoReflector *right_reflector_;
};


#endif //LABORATORY_WORK_IN_INFORMATION_ENGINEERING_III_LINETRACECAR_H

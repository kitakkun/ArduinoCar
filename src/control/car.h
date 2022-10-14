#ifndef CAR_H
#define CAR_H

#include "wheel.h"
#include "photo_reflector.h"
#include "brain.h"

class CarBuilder;

class Car {
public:
    Car(CarBuilder *builder);
    void UpdateSensors();
    void Action();
private:
    Brain *brain_;           // 行動決定（アルゴリズム実装クラス）
    Wheel *left_wheel_;     // 左の車輪
    Wheel *right_wheel_;    // 右の車輪
    PhotoReflector *left_reflector_;    // 左のセンサ
    PhotoReflector *right_reflector_;   // 右のセンサ
    PhotoReflector *front_reflector_;   // 真ん中のセンサ
};

#endif

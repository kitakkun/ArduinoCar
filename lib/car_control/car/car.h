#ifndef CAR_H
#define CAR_H

#include "component/wheel/wheel.h"
#include "component/sensor/photo_reflector.h"
#include "control/brain/brain.h"
#include "model/car_state.h"
#include "control/instruction/instruction.h"

class CarBuilder;   // 循環参照防止

class Car {
public:
    explicit Car(CarBuilder *builder);  // コンストラクタ（Builderを使って作る）
    void UpdateSensors();           // センサー情報の更新
    CarState CollectCarState();     // センサー情報や車輪の回転情報など車に関する情報を取得
    Instruction *Think(CarState state);  // 次に取るべき行動を決定する
    void SetInstruction(Instruction *instruction);
    void Act();  // 決定した行動を実行に写す
private:
    Instruction *instruction_;   // 実行中の指令
    Brain *brain_;           // 行動決定（アルゴリズム実装クラス）
    Wheel *left_wheel_;     // 左の車輪
    Wheel *right_wheel_;    // 右の車輪
    PhotoReflector *left_reflector_;    // 左のセンサ
    PhotoReflector *right_reflector_;   // 右のセンサ
    PhotoReflector *front_reflector_;   // 真ん中のセンサ
};

#endif

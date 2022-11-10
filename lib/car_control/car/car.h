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
    /**
     * builderのパラメータを元にインスタンスを生成します。
     * @param builder CarBuilderのインスタンス
     */
    explicit Car(CarBuilder *builder);

    /**
     * センサー情報を更新します。
     */
    void UpdateSensors();

    /**
     * センサー情報や車輪の回転情報など車に関する情報を返す。
     * @return 車の状態情報
     */
    CarState CollectCarState();

    /**
     * 次に取るべき行動を決定する（Brainクラスが決定した指令が返る）。
     * @param state 判断材料となる車の状態情報
     * @return 取るべきだと判断した行動
     */
    Instruction *Think(CarState state);

    /**
     * 指令をセットします。
     * @param instruction セットする指令
     */
    void SetInstruction(Instruction *instruction);

    /**
     * 設定されている指令を実行に移す。
     */
    void Act();

private:
    Instruction *instruction_;   /// 設定中の指令
    Instruction *interruptInstruction_ = nullptr;
    Brain *brain_;          /// 車の状態を見て指令を送るアルゴリズム実装部
    Wheel *left_wheel_;     /// 左の車輪
    Wheel *right_wheel_;    /// 右の車輪
    PhotoReflector *front_left_reflector_;    /// 左のセンサ
    PhotoReflector *front_right_reflector_;   /// 右のセンサ
    PhotoReflector *front_mid_reflector_;   /// 真ん中のセンサ
    PhotoReflector *back_left_reflector_;    /// 左のセンサ
    PhotoReflector *back_right_reflector_;   /// 右のセンサ
    PhotoReflector *back_mid_reflector_;   /// 真ん中のセンサ
};

#endif

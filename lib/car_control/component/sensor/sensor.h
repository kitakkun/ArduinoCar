#ifndef SENSOR_DATA_H
#define SENSOR_DATA_H

/**
 * センサークラス
 * センサー値の更新・保持・提供を行う
 */
class Sensor {
public:
    /**
     * コンストラクタ
     * @param pin ピン番号
     */
    explicit Sensor(int pin);

    /**
     * センサー値を更新
     */
    void Update();

    /**
     * センサー値の取得（生のデータ）
     * @return 生のセンサー値
     */
    int RawValue() const;

private:
    int pin_;       /// センサーのピン番号
    int value_;     /// センサーの値
};

#endif
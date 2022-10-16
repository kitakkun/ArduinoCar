#ifndef SENSOR_DATA_H
#define SENSOR_DATA_H

/**
 * センサークラス（センサーの値更新・提供）
 */
class Sensor {
public:
    explicit Sensor(int pin);
    void Update();
    int RawValue() const;
private:
    int pin_;
    int value_;
};

#endif

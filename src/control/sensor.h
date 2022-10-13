#ifndef SENSOR_DATA_H
#define SENSOR_DATA_H

/**
 * センサークラス（センサーの値更新・提供）
 */
class Sensor {
    public:
        Sensor(int pin);
        void Update();
        int CurrentValue();
    private:
        int pin_;
        int value_;
};

#endif

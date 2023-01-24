#ifndef LABORATORY_WORK_IN_INFORMATION_ENGINEERING_III_CAR_CONTROLLER_H
#define LABORATORY_WORK_IN_INFORMATION_ENGINEERING_III_CAR_CONTROLLER_H

/**
 * 車の制御クラスのインタフェース
 */
class CarController {
public:
    /* センサー値を利用してモータを制御 */
    virtual void Operate() = 0;

    /* センサーなどのリフレッシュ処理 */
    virtual void Update() = 0;
};


#endif //LABORATORY_WORK_IN_INFORMATION_ENGINEERING_III_CAR_CONTROLLER_H

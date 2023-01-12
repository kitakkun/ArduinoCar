#ifndef LABORATORY_WORK_IN_INFORMATION_ENGINEERING_III_PID_CONTROLLER_H
#define LABORATORY_WORK_IN_INFORMATION_ENGINEERING_III_PID_CONTROLLER_H

#define ERROR_MEM_COUNT 10

/**
 * 汎用PIDコントローラ
 */
class PIDController {
public:
    explicit PIDController(double p_weight, double i_weight, double d_weight);

    double CalcManipulation(double actual, double target);

private:
    double p_weight_;
    double i_weight_;
    double d_weight_;

    double prev_deviation_;
    double errors_[ERROR_MEM_COUNT];
    int error_cursor_;
    unsigned long last_time_called_;
};


#endif //LABORATORY_WORK_IN_INFORMATION_ENGINEERING_III_PID_CONTROLLER_H

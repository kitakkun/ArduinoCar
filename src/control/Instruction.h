#ifndef INSTRUCTION_H
#define INSTRUCTION_H

// 車に対する指令
struct Instruction {
    int l_wheel_speed;      // 左車輪のスピード
    int r_wheel_speed;      // 右車輪のスピード
    MoveDirection l_wheel_direction;    // 左車輪の回転方向
    MoveDirection r_wheel_direction;    // 右車輪の回転方向
    int duration_millis;                // 処理にかける時間
    bool enable_interpolation;          // 速度更新で補間を有効にするか
    bool force;     // 強制実行するかどうか
};

#endif //INSTRUCTION_H

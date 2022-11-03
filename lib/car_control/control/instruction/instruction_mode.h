#ifndef LABORATORY_WORK_IN_INFORMATION_ENGINEERING_III_INSTRUCTION_MODE_H
#define LABORATORY_WORK_IN_INFORMATION_ENGINEERING_III_INSTRUCTION_MODE_H

enum InstructionMode {
    interrupt, /// 中断モード（タスク終了後以前実行していたInstructionに戻る）
    force,     /// 強制実行モード（以前実行していたInstructionをクリア）
    normal,    /// 基本モード（先行処理があったら実行しない）
};

#endif //LABORATORY_WORK_IN_INFORMATION_ENGINEERING_III_INSTRUCTION_MODE_H

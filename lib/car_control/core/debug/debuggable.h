#ifndef LABORATORY_WORK_IN_INFORMATION_ENGINEERING_III_DEBUGGABLE_H
#define LABORATORY_WORK_IN_INFORMATION_ENGINEERING_III_DEBUGGABLE_H

#include "serstream"

/**
 * Loggerクラスによるデバッグを可能にするクラス
 */
class Debuggable {
public:
    explicit Debuggable(String tag, bool enable_debug = true) {
        this->tag_ = tag;
        this->enable_debug = enable_debug;
    }

    String Tag() const { return this->tag_; }

    bool EnableDebug() const { return this->enable_debug; }

private:
    String tag_;
    bool enable_debug;
};


#endif //LABORATORY_WORK_IN_INFORMATION_ENGINEERING_III_DEBUGGABLE_H

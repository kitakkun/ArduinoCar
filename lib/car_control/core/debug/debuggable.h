#ifndef LABORATORY_WORK_IN_INFORMATION_ENGINEERING_III_DEBUGGABLE_H
#define LABORATORY_WORK_IN_INFORMATION_ENGINEERING_III_DEBUGGABLE_H

#include "serstream"

class Debuggable {
public:
    explicit Debuggable(String tag) {
        this->tag_ = tag;
    }

    virtual String Tag() { return this->tag_; }

private:
    String tag_;
};


#endif //LABORATORY_WORK_IN_INFORMATION_ENGINEERING_III_DEBUGGABLE_H

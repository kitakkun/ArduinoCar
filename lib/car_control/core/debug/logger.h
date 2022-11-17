#ifndef LABORATORY_WORK_IN_INFORMATION_ENGINEERING_III_LOGGER_H
#define LABORATORY_WORK_IN_INFORMATION_ENGINEERING_III_LOGGER_H

#include "custom/data_model/line_trace_car_state.h"
#include "ArduinoLog.h"

class Logger {
private:
    template<class T>
    static String BuildStringWithInstanceInfo(T msg) {
        return String("[%s@%X] ") + String(msg);
    }

public:

    template<class T, typename... Args>
    static void Verboseln(Debuggable *instance, T msg, Args... args) {
        if (!instance->EnableDebug()) return;
        String msg_out = BuildStringWithInstanceInfo(msg);
        Log.verboseln(msg_out.c_str(), instance->Tag().c_str(), instance, args...);
    }

    template<class T, typename... Args>
    static void Warningln(Debuggable *instance, T msg, Args... args) {
        if (!instance->EnableDebug()) return;
        String msg_out = BuildStringWithInstanceInfo(msg);
        Log.warningln(msg_out.c_str(), instance->Tag().c_str(), instance, args...);
    }

    template<class T, typename... Args>
    static void Errorln(Debuggable *instance, T msg, Args... args) {
        if (!instance->EnableDebug()) return;
        String msg_out = BuildStringWithInstanceInfo(msg);
        Log.errorln(msg_out.c_str(), instance->Tag().c_str(), instance, args...);
    }

    template<class T, typename... Args>
    static void Fatalln(Debuggable *instance, T msg, Args... args) {
        if (!instance->EnableDebug()) return;
        String msg_out = BuildStringWithInstanceInfo(msg);
        Log.fatalln(msg_out.c_str(), instance->Tag().c_str(), instance, args...);
    }
};


#endif //LABORATORY_WORK_IN_INFORMATION_ENGINEERING_III_LOGGER_H

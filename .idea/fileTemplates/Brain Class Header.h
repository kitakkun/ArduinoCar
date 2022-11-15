#parse("C File Header.h")
#[[#ifndef]]# ${INCLUDE_GUARD}
#[[#define]]# ${INCLUDE_GUARD}
#[[#include]]# "core.h"

#set( $ActivityState = "${NAME}ActivityState" )
#set( $CarState = "${NAME}CarState" )

${NAMESPACES_OPEN_CPP}

enum ${ActivityState} {
    someState
};

class ${CarState} {
};

class ${NAME} : public Brain {
public:
    void SetCurrentCarState(${CarState} car_state);
    Instruction *CalculateNextInstruction() override;
private:
    ${CarState} current_car_state_;
    ${ActivityState} activity_state_;
};

${NAMESPACES_CLOSE_CPP}

#[[#endif]]# // ${INCLUDE_GUARD}

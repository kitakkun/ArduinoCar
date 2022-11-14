#parse("C File Header.h")
#[[#include]]# "${HEADER_FILENAME}"

#set( $ActivityState = "${NAME}ActivityState" )
#set( $CarState = "${NAME}CarState" )

${NAMESPACES_OPEN_CPP}

void ${NAME}::SetCurrentCarState(${CarState} car_state) {
    this->current_car_state_ = car_state;
}

Instruction *${NAME}::CalculateNextInstruction() {
    return nullptr;
}

${NAMESPACES_CLOSE_CPP}

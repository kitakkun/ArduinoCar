#include "brain.h"
#include "core/debug/logger.h"

Brain::Brain(String tag) : Debuggable(tag) {
    Logger::Verboseln(this, "Instantiated");
}


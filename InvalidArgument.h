#ifndef INVALIDARGUMENT_H
#define INVALIDARGUMENT_H

#include <string>
#include <sstream>
#include "LogicError.h"

class InvalidArgument : public LogicError {
public:

    InvalidArgument( int argument ) : LogicError( argument ) {
        std::stringstream stream;
        stream << argument;
        m_message = "Argument " + stream.str( ) + " mush be multiple of 5";
    }
};

#endif // INVALIDARGUMENT_H

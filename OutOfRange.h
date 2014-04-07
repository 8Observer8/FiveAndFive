#ifndef OUTOFRANGE_H
#define OUTOFRANGE_H

#include <string>
#include <sstream>
#include "LogicError.h"

class OutOfRange : public LogicError {
public:

    OutOfRange( int argument, int beginOfRange, int endOfRange ) : LogicError( argument ) {
        std::string str_argument, str_beginOfRange, str_endOfRange;

        str_argument = intToString( argument );
        str_beginOfRange = intToString( beginOfRange );
        str_endOfRange = intToString( endOfRange );

        m_message = "Argument " + str_argument + " don't hit on the range [" +
                str_beginOfRange + ", " + str_endOfRange + "]";
    }

private:
    std::string intToString( int number ) {
        std::stringstream stream;
        stream << number;
        return stream.str( );
    }
};

#endif // OUTOFRANGE_H

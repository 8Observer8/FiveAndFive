#ifndef LOGICERROR_H
#define LOGICERROR_H

#include <string>
#include <stdexcept>

class LogicError : public std::logic_error {
public:

    LogicError( int argument ) : std::logic_error( "" ), m_argument( argument ) {

    }

    virtual const char *what( ) const throw () {
        return m_message.c_str( );
    }

    virtual ~LogicError( ) throw () {

    }

protected:
    int m_argument;
    std::string m_message;
};

#endif // LOGICERROR_H

#ifndef FILEERROR_H
#define FILEERROR_H

#include <string>
#include <stdexcept>

class FileError : public std::runtime_error {
public:

    FileError( const std::string &fileIn ) : std::runtime_error( "" ), m_file( fileIn ) {
    }

    virtual const char* what( ) const throw() {
        return m_msg.c_str( );
    }

    virtual ~FileError() throw() {

    }

protected:
    std::string m_file;
    std::string m_msg;
};

#endif // FILEERROR_H

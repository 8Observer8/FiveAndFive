#ifndef FILEREADERROR_H
#define FILEREADERROR_H

#include <string>
#include <sstream>
#include "FileError.h"

class FileReadError : public FileError {
public:

    FileReadError( const std::string &fileNameIn, int lineNumIn ) :
        FileError( fileNameIn ), m_lineNum( lineNumIn ) {
        std::ostringstream ostr;
        ostr << "Error reading " << fileNameIn << " at line " << lineNumIn;
        m_msg = ostr.str( );
    }

protected:
    int m_lineNum;
};

#endif // FILEREADERROR_H

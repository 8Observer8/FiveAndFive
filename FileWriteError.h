#ifndef FILEWRITEERROR_H
#define FILEWRITEERROR_H

#include <string>
#include "FileError.h"

class FileWriteError : public FileError {
public:

    FileWriteError( const std::string &fileNameIn ) : FileError( fileNameIn ) {
        m_msg = "Unable to write " + fileNameIn;
    }
};

#endif // FILEWRITEERROR_H

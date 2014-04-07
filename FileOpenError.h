#ifndef FILEOPENERROR_H
#define FILEOPENERROR_H

#include <string>
#include "FileError.h"

class FileOpenError : public FileError {
public:

    FileOpenError( const std::string &fileNameIn ) : FileError( fileNameIn ) {
        m_msg = "Unable to open " + fileNameIn;
    }
};

#endif // FILEOPENERROR_H

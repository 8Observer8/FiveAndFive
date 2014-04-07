#include <QCoreApplication>
#include <iostream>
#include <fstream>
#include "FiveAndFive.h"
#include "FileError.h"
#include "FileOpenError.h"
#include "FileReadError.h"
#include "FileWriteError.h"
#include "LogicError.h"

void readData( const std::string &fileName, int &number )
throw (FileOpenError, FileReadError);

void writeResult( const std::string &fileName, int result )
throw (FileOpenError, FileWriteError);

int main( int argc, char *argv[] ) {
    QCoreApplication a( argc, argv );

    std::string fileNameIn = "input.txt";
    int number = 0;

    try {
        readData( fileNameIn, number );
    } catch ( const FileError &e ) {
        std::cerr << e.what( ) << std::endl;
        return 1;
    } catch ( ... ) {
        std::cerr << "Uncaught exception." << std::endl;
        return 1;
    }

    int result = 0;
    FiveAndFive faf;
    try {
        result = faf.fiveAndFive( number );
    } catch ( const LogicError &e ) {
        std::cerr << e.what( ) << std::endl;
        return 1;
    } catch ( ... ) {
        std::cerr << "Uncaught exception." << std::endl;
        return 1;
    }

    std::string fileNameOut = "output.txt";
    try {
        writeResult( fileNameOut, result );
    } catch ( const FileError &e ) {
        std::cerr << e.what( ) << std::endl;
        return 1;
    }

    std::cout << "See file " << fileNameOut << std::endl;

    return a.exec( );
}

void readData( const std::string &fileName, int &number )
throw ( FileOpenError, FileReadError) {
    std::ifstream file;
    file.open( fileName.c_str( ) );
    if ( file.fail( ) ) {
        throw FileOpenError( fileName );
    }

    int lineNumIn = 0;
    if ( !(file >> number) ) {
        lineNumIn++;
        throw FileReadError( fileName, lineNumIn );
    }
}

void writeResult( const std::string &fileName, int result )
throw (FileOpenError, FileWriteError) {
    std::ofstream file;
    file.open( fileName.c_str( ) );

    if ( file.fail( ) ) {
        throw FileOpenError( fileName );
    }

    if ( !(file << result) ) {
        throw FileWriteError( fileName );
    }

    file << std::endl;
}

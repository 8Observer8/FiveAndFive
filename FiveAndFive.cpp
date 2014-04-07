#include "FiveAndFive.h"

double FiveAndFive::fiveAndFive( int number ) throw (InvalidArgument, OutOfRange) {
    if ( (number % 5) != 0 ) {
        throw InvalidArgument( number );
    }

    const int beginOfRange = 5;
    const int endOfRange = 400000;
    if ( (number < beginOfRange) || (endOfRange < number) ) {
        throw OutOfRange( number, beginOfRange, endOfRange );
    }

    double result = (double) number * (double) number;
    return result;
}

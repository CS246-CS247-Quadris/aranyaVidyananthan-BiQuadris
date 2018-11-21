#include "cell.h"

Cell::Cell( int x, int y ): isempty{false}, x{x}, y{y}, t{}{}


Cell::~Cell() {}


const char Cell::getType() { 
    if ( isempty ) { return t; }
    else { return 'a'; } // an error cell does not contain a block 
}

void Cell::setType(char type) {
    t = type;
}


bool Cell::getStatus() {
    return isempty;
}

void Cell::setStatus( bool status ) {
    isempty = status;
}


const int getX() {
    return x;
}


const int getY() {
    return y;
}


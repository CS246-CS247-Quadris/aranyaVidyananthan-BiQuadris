#include "cell.h"
#include <iostream>

Cell::Cell( int x, int y ): isempty{true}, t{}, x{x}, y{y}{}


Cell::~Cell() {}


const char Cell::getType() { 
    if (!(isempty )) { return t; }
    else { return ' '; } // an error cell does not contain a block 
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


const int Cell::getX() {
    return x;
}


const int Cell::getY() {
    return y;
}

void Cell::print() {
    if (!(isempty )) { 
        std::cout << t;
    }
    else { std::cout << ' '; } 
}

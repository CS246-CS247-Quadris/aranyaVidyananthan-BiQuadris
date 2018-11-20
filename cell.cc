

Cell::Cell( int x, int y ): isempty{false}, x{x}, y{y}, t{a}{}


Cell::~Cell() {}


const char getType() { 
    if ( isempty ) { return t; }
    else { return a; } // an error cell does not contain a block 
}

void setType(char type) {
    t = type;
}


bool getStatus() {
    return isempty;
}

void setStatus( bool status ) {
    isempty = status;
}


const int getX() {
    return x;
}


const int getY() {
    return y;
}

#include "block.h"
#include "zblock.h"
#include "board.h"
#include "cell.h"


ZBlock::ZBlock( Board * g ) : Block{'z', g}{}


ZBlock::~ZBlock() {
    shape.clear();
    shape.shrink_to_fit();
    temp.clear();
    temp.shrink_to_fit();
}


bool ZBlock::set () override {
    // check if the four cells needed for block are empty
    if( (g.cells[0][2]).getStatus()  == true ) {
        temp.emplaceback( g.cells[0][2] );
    }
    else { temp.clear(); return false; }
    if( (g.cells[1][3]).getStatus()  == true ) {
        temp.emplaceback( g.cells[1][3] );
    }
    else { temp.clear(); return false; }
    if( (g.cells[2][3]).getStatus() == true ) {
        temp.emplaceback( g.cells[2][3] );
    }
    else { temp.clear(); return false; }
    if( (g.cells[1][2]).getStatus() == true ) {
        temp.emplaceback( g.cells[1][2] );
    }
    else { temp.clear(); return false; }
    for ( n:shape) {
        shape[n] = temp[n];
        shape[n].setType( 'z' );
        shape[n].setStatus( false );
    }
    temp.clear();
    return true;
}


bool ZBlock::move( int direction ) override {
    for ( auto n:shape ) { (shape[n]).setStatus( true ); }

        // check if the shape cells can move, add cells to temp vector
    for ( auto i:shape ) {
        // set the new x and y cells based on direction moving
        if ( direction == 2 ) { // right
            int a = shape[i].getX() + 1;
            int b = shape[i].getY();
        }
        if ( direction == 3 ) { // down
            int a = shape[i].getX();
            int b = shape[i].getY() + 1;
        }
        if ( direction == 4 ) { // left
            int a = shape[i].getX() - 1;
            int b = shape[i].getY();
        }

        if ( a >= 0 && a < 11 && b >= 0 && b < 18 && g.cells[a][b].getStatus() == true ) { temp.emplaceback( g.cells[a][b] ); }
        else {
            for ( auto k:shape ) { shape[n].setStatus( false ); }
            temp.clear();
            return false;
        }
   }

    // set new shape to the temp cells
    for ( auto n:shape ) {
        shape[n].setStatus( true ); // set old shape cells to empty
        shape[n] = temp[n];
        shape[n].setType( 'z' );
        shape[n].setStatus( false ); // set new cells to full
    }
    return true;
}


const char ZBlock::getType() override {
    return type;
}


bool ZBlock::rotate( int direction ) override {

}


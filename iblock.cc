#include "block.h"
#include "iblock.h"
#include "board.h"
#include "cell.h"


IBlock::IBlock( Board * g ) : Block{'i', g}{}


IBlock::~IBlock() {
    shape.clear();
    shape.shrink_to_fit();
    temp.clear();
    temp.shrink_to_fit();
}


bool IBlock::set () {
    // check if the four cells needed for block are empty
    if( (g->cells[0][3]).getStatus()  == true ) {
        temp.emplaceback( g->cells[0][3] );
    }
    else { temp.clear(); return false; }
    if( (g->cells[1][3]).getStatus()  == true ) {
        temp.emplaceback( g->cells[1][3] );
    }
    else { temp.clear(); return false; }
    if( (g->cells[2][3]).getStatus() == true ) {
        temp.emplaceback( g->cells[2][3] );
    }
    else { temp.clear(); return false; }
    if( (g->cells[3][3]).getStatus() == true ) {
        temp.emplaceback( g->cells[3][3] );
    }
    else { temp.clear(); return false; }
    for ( n:shape) {
        shape[n] = temp[n];
        shape[n].setType( 'i' );
        shape[n].setStatus( false );
    }
    temp.clear();
    return true;
}


bool IBlock::move( int direction ) override {
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
        shape[n].setType( 'i' );
        shape[n].setStatus( false ); // set new cells to full
    }
    return true;
}


const char IBlock::getType() override {
    return type;
}

// direction = 1, means clockwise, -1 means couterclockwise
bool IBlock::rotate( int direction ) override {
    for ( std::vector < Cell * >::iterator n = shape.begin(); n != shape.end(); ++n) {
        n.setStatus( true };
    }
    if ( direction == 1 ) {  //clockwise
        if ( orientation + direction == 5 ) { direction = 1; }
        else { direction == orientation + direction; }
    }
    else { // counterclockwise
        if ( orientation + direction == 0 ) { direction = 4; }
        else { direction = orientation + direction; } 
    }
// now direction is the new orientation of the block
    
}


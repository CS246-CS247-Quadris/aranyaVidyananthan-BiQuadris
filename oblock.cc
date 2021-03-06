#include "block.h"
#include "oblock.h"
#include "board.h"
#include "cell.h"
#include <iostream>


OBlock::OBlock(int level, Board * g ): Block{level,'O', g }{}


OBlock::~OBlock() {
    shape.clear();
    shape.shrink_to_fit();
    temp.clear();
    temp.shrink_to_fit();
}


bool OBlock::set () {
    // check if the four cells needed for block are empty
    if( (g->getCell(0,3))->getStatus()  == true ) {
        temp.emplace_back( g->getCell(0,3));
    }
    else { temp.clear(); return false; }
    if( (g->getCell(1,3))->getStatus()  == true ) {
        temp.emplace_back( g->getCell(1,3));
    }
    else { temp.clear(); return false; }
    if( (g->getCell(0,2))->getStatus() == true ) {
        temp.emplace_back( g->getCell(0,2) );
    }
    else { temp.clear(); return false; }
    if( (g->getCell(1,2))->getStatus() == true ) {
        temp.emplace_back( g->getCell(1,2));
    }
    else { temp.clear(); return false; }
    
    for (int index = 0; index < 4; index ++) {
        shape.emplace_back(temp[index]);
        shape[index]->setType( 'O' );
        shape[index]->setStatus( false );
        if ( g->getDisplay() ) { g->getDisplay()->fillRectangle( ( shape[index]->getX() + g->getX() )*scale, ( shape[index]->getY() + g->getY() )*scale, scale, scale, 7 ); }
    }
    temp.clear();
    return true;
}


bool OBlock::move( int direction ){
    for ( int n = 0; n < 4; n++ ) {
         shape[n]->setStatus( true );
         }

        // check if the shape cells can move, add cells to temp vector
    for ( int i = 0; i < 4; i ++ ) {
        // set the new x and y cells based on direction moving
        int a = 0;
        int b = 0;
        if ( direction == 2 ) { // right
            a = (shape[i]->getX()) + 1;
            b = (shape[i]->getY());
        }
        if ( direction == 3 ) { // down
            a = shape[i]->getX();
            b = (shape[i]->getY()) + 1;
        }
        if ( direction == 4 ) { // left
            a = (shape[i]->getX()) - 1;
            b = shape[i]->getY();
        }

        if ( a >= 0 && a < 11 && b >= 0 && b < 18 && g->getCell(a,b)->getStatus() == true ){ 
            temp.emplace_back( g->getCell(a,b) );
        }else {
            for(int k = 0; k < 4; k++){
               shape[k]->setStatus(false);
            }
            temp.clear();
            return false;
        }    
   }

    // set new shape to the temp cells
    for ( int index = 0; index < 4; index++ ) {
        shape[index]->setStatus( true ); // set old shape cells to empty
        shape[index]->setType(' '); // set old shape cella to no type
        if ( g->getDisplay() ) { g->getDisplay()->fillRectangle( ( shape[index]->getX() + g->getX() )*scale, ( shape[index]->getY() + g->getY() )*scale, scale, scale, 0 ); }
    }
    shape.clear();
    for ( int index = 0; index < 4; index++ ) {
        shape.emplace_back( temp[index] );
        shape.back()->setType( 'O' );
        shape.back()->setStatus( false ); // set new cells to full
        if ( g->getDisplay() ) { g->getDisplay()->fillRectangle( ( shape[index]->getX() + g->getX() )*scale, ( shape[index]->getY() + g->getY() )*scale, scale, scale, 7 ); }
    }

    temp.clear();
    return true;
}


const char OBlock::getType(){
    return type;
}


// direction = 1, means clockwise, -1 means couterclockwise
bool OBlock::rotate( int direction ) {
    if ( direction == 1 ) {  //clockwise
        if ( orientation + direction == 5 ) { orientation = 1; }
        else { orientation = orientation + direction; }
    }
    else { // counterclockwise
        if ( orientation + direction == 0 ) { orientation = 4; }
        else { orientation = orientation + direction; } 
    }
// now direction is the new orientation of the block
    return true;
}


void OBlock::print() {
    if ( g->getPlayer() == 2 ) { std::cout << "                  "; }
    std::cout << "OO" << std::endl;
    if ( g->getDisplay() ) { g->getDisplay()->fillRectangle( ( 0 + g->getX() )*scale, ( 21 + g->getY() )*scale, scale*2, scale*2, 7 ); }
    if ( g->getPlayer() == 2 ) { std::cout << "                  "; }
    std::cout << "OO" << std::endl;
    if ( g->getDisplay() ) { g->getDisplay()->fillRectangle( ( 0 + g->getX() )*scale, ( 22 + g->getY() )*scale, scale*2, scale*2, 7 ); }
}


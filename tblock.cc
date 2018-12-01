#include "block.h"
#include "tblock.h"
#include "board.h"
#include "cell.h"
#include <iostream>

TBlock::TBlock( Board * g ): Block{'T', g }{}


TBlock::~TBlock() {
    shape.clear();
    shape.shrink_to_fit();
    temp.clear();
    temp.shrink_to_fit();
}


bool TBlock::set () {
    // check if the four cells needed for block are empty
    if( (g->getCell(0,2))->getStatus()  == true ) {
        temp.emplace_back( g->getCell(0,2));
    }
    else { temp.clear(); return false; }
    if( (g->getCell(1,3))->getStatus()  == true ) {
        temp.emplace_back( g->getCell(1,3));
    }
    else { temp.clear(); return false; }
    if( (g->getCell(1,2))->getStatus() == true ) {
        temp.emplace_back( g->getCell(1,2) );
    }
    else { temp.clear(); return false; }
    if( (g->getCell(2,2))->getStatus() == true ) {
        temp.emplace_back( g->getCell(2,2));
    }
    else { temp.clear(); return false; }
    
    for (int index = 0; index < 4; index ++) {
        shape.emplace_back(temp[index]);
        shape[index]->setType( 'T' );
        shape[index]->setStatus( false );
    }
    temp.clear();
    return true;
}


bool TBlock::move( int direction ){
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
            //for ( auto k:shape ) { shape[n].setStatus( false ); }
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
    }
    shape.clear();
    for ( int index = 0; index < 4; index++ ) {
        shape.emplace_back( temp[index] );
        shape.back()->setType( 'T' );
        shape.back()->setStatus( false ); // set new cells to full
    }

    temp.clear();
    return true;
}


const char TBlock::getType(){
    return type;
}


// direction = 1, means clockwise, -1 means couterclockwise
bool TBlock::rotate( int direction ) {
    for (int n = 0; n < 4; n++) {
        shape[n]->setStatus( true );
    }
    if ( direction == 1 ) {  //clockwise
        if ( orientation + direction == 5 ) { direction = 1; }
        else { direction = orientation + direction; }
    }
    else { // counterclockwise
        if ( orientation + direction == 0 ) { direction = 4; }
        else { direction = orientation + direction; } 
    }
// now direction is the new orientation of the block
    return true;
}


void TBlock::print() {
    if ( g->getPlayer() == 2 ) { std::cout << "                  "; }
    std::cout << "TTT" << std::endl;
    if ( g->getPlayer() == 2 ) { std::cout << "                  "; }
    std::cout << " T " << std::endl;
}



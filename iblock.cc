#include "block.h"
#include "iblock.h"
#include "board.h"
#include "cell.h"
#include <iostream>
#include "window.h"



IBlock::IBlock( int level,Board * g ): Block{level,'I', g }{}


IBlock::~IBlock() {
    shape.clear();
    shape.shrink_to_fit();
    temp.clear();
    temp.shrink_to_fit();
}


bool IBlock::set () {
    // check if the four cells needed for block are empty
    if( (g->getCell(0,3))->getStatus() == true ) {
        temp.emplace_back( g->getCell(0,3));
    }
    else { temp.clear(); return false; }
    if( (g->getCell(1,3))->getStatus() == true ) {
        temp.emplace_back( g->getCell(1,3));
    }
    else { temp.clear(); return false; }
    if( (g->getCell(2,3))->getStatus() == true ) {
        temp.emplace_back( g->getCell(2,3) );
    }
    else { temp.clear(); return false; }
    if( (g->getCell(3,3))->getStatus() == true ) {
        temp.emplace_back( g->getCell(3,3));
    }
    else { temp.clear(); return false; }
    for (int index = 0; index < 4; index ++) {
        shape.emplace_back(temp[index]);
        shape[index]->setType( 'I' );
        shape[index]->setStatus( false );
        if ( g->getDisplay() ) { g->getDisplay()->fillRectangle( ( shape[index]->getX() + g->getX() )*scale , ( shape[index]->getY() + g->getY() )*scale , scale, scale, 2 ); }
    }
    temp.clear();
    return true;
}


bool IBlock::move( int direction ){
    for ( int n = 0; n < 4; ++n ) {
         shape[n]->setStatus( true );
    }

    // check if the shape cells can move, add cells to temp vector
    for ( int i = 0; i < 4; ++i ) {
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
        }
        else {
            for(int k = 0; k < 4; ++k ){
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
std::cout << shape.back()->getX() << " " << shape.back()->getY() << std::endl;
        shape.back()->setType( 'I' );
        shape.back()->setStatus( false ); // set new cells to full
        if ( g->getDisplay() ) { g->getDisplay()->fillRectangle( ( shape.back()->getX() + g->getX() )*scale, ( shape.back()->getY() + g->getY() )*scale , scale, scale, 2 ); }
    }
    temp.clear();
    return true;
}


const char IBlock::getType(){
    return type;
}


// direction = 1, means clockwise, -1 means couterclockwise
bool IBlock::rotate( int direction ) {
    for (int n = 0; n < 4; n++) { // set the old cells to empty
        shape[n]->setStatus( true );
    }
    int count = 0;
    // check if the shape cells can move, add cells to temp vector
    for ( int i = 0; i < 4; ++i ) {
        int a = 0;
        int b = 0;
        if (( orientation == 1 ) || ( orientation == 3 )) {
            a = shape[0]->getX();
            b = shape[i]->getY() - count;
            ++count;
        }
        else {
            a = shape[i]->getX() + count;
            b = shape[0]->getY();
            ++count;
        }            
        if ( a >= 0 && a < 11 && b >= 0 && b < 18 && g->getCell(a,b)->getStatus() == true ){
std::cout << a << " " << b << std::endl;
            temp.emplace_back( g->getCell(a,b) );
        }
        else {
            for( int k = 0; k < 4; ++k ){
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
        if ( g->getDisplay() ) { g->getDisplay()->fillRectangle( ( shape[index]->getX() + g->getX() )*scale , ( shape[index]->getY() + g->getY() )*scale , scale, scale, 0 ); }
    }
    shape.clear();
    for ( int index = 0; index < 4; index++ ) {
        shape.emplace_back( temp[index] );
        shape.back()->setType( 'I' );
        shape.back()->setStatus( false ); // set new cells to full
        if ( g->getDisplay() ) { g->getDisplay()->fillRectangle( ( shape[index]->getX() + g->getX() )*scale, ( shape[index]->getY() + g->getY() )*scale, scale, scale, 2 ); }
    }
    temp.clear();
    // sets new orientation of block
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


void IBlock::print() {
    if ( g->getPlayer() == 2 ) { std::cout << "                  "; }
    std::cout << "IIII" << std::endl;
    if ( g->getDisplay() ) { g->getDisplay()->fillRectangle( ( 0 + g->getX() )*scale, ( 21 + g->getY() )*scale, scale*4, scale, 2 ); }
}

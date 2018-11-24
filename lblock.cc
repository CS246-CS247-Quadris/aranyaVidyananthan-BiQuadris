#include "block.h"
#include "lblock.h"


LBlock::LBlock( char type, Board * g ) : shape{}, temp{}, type{type}, orientation{1}, g{g}, removed{0}{}
   

LBlock::~LBlock() { 
    for ( auto n:shape ) { delete shape[n]; }
    for ( auto m:temp ) { delete shape[m]; }
}


bool LBlock::set () {
    if( g.cells[0][3] == isempty ) { 
        temp[0] = g.cells[0][3];
    }
    if( g.cells[1][3] == isempty ) { 
        temp[1] = g.cells[1][3];
    }
    if( g.cells[2][3] == isempty ) { 
      
    }
    if( g.cells[2][2] == isempty ) { 
      
    }
}


bool move( int direction ) override {

}


const char getType() override {
  
}


bool rotate( int direction ) override {
  
}

  
void attachCell( Cell* c ) override {
  
}

  
void detachCell( Cell* c ) override {
  
}

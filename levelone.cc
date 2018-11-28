#include <stdlib.h>
#include "levelone.h"
#include "block.h"
#include "sblock.h"
#include "zblock.h"
#include "tblock.h"
#include "iblock.h"
#include "jblock.h"
#include "lblock.h"
#include "oblock.h"

//constructor
LevelOne::LevelOne( Board * board ): Level{1, board}{}


//destructor
LevelOne::~LevelOne(){

}

//get the Level number
const int LevelOne::getLevel(){
    return levelNumber;
}

//using random number to control the probability of
//which type of new block is generated
Block* LevelOne::nextBlock(){
    Block *block;
    int rn = rand()%12; // rn in the range 0 to 11
    if(rn == 0){
       block = new SBlock( board );
       if ( block->set() == false) { /* there isnt space to create the block */}
    }else if(rn == 1){
       block = new ZBlock( board );
       if ( block->set() == false) { /* there isnt space to create the block */ }
    }else if(rn == 2 || rn == 3){
       block = new TBlock( board );
       if ( block->set() == false) { /* there isnt space to create the block */ }
    }else if(rn == 4 || rn == 5){
       block = new IBlock( board );
       if ( block->set() == false) { /* there isnt space to create the block */ }
    }else if(rn == 6 || rn == 7){
       block = new JBlock( board );
       if ( block->set() == false) { /* there isnt space to create the block */ }
    }else if(rn == 8 || rn == 9){
       block = new LBlock( board );
       if ( block->set() == false) { /* there isnt space to create the block */ }
    }else{
       block = new OBlock( board );
       if ( block->set() == false) { /* there isnt space to create the block */ }
    }
    return block;
}



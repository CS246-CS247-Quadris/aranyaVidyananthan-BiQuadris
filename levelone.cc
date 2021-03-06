#include <cstdlib>
#include "levelone.h"
#include "sblock.h"
#include "zblock.h"
#include "tblock.h"
#include "iblock.h"
#include "jblock.h"
#include "lblock.h"
#include "oblock.h"

using namespace std;

class Board;

//constructor
LevelOne::LevelOne(): Level{1}{}


//destructor
LevelOne::~LevelOne(){

}

//get the Level number
const int LevelOne::getLevel(){
    return levelNumber;
}

//using random number to control the probability of
//which type of new block is generated
Block* LevelOne::nextBlock( Board * board, string t ){
    Block *block;
    t = "...";
    int rn = rand()%12; // rn in the range 0 to 11
    if(rn == 0){
       block = new SBlock(1, board );
       if ( block->set() == false) { /* there isnt space to create the block */}
    }else if(rn == 1){
       block = new ZBlock( 1,board );
       if ( block->set() == false) { /* there isnt space to create the block */ }
    }else if(rn == 2 || rn == 3){
       block = new TBlock( 1,board );
       if ( block->set() == false) { /* there isnt space to create the block */ }
    }else if(rn == 4 || rn == 5){
       block = new IBlock(1, board );
       if ( block->set() == false) { /* there isnt space to create the block */ }
    }else if(rn == 6 || rn == 7){
       block = new JBlock(1, board );
       if ( block->set() == false) { /* there isnt space to create the block */ }
    }else if(rn == 8 || rn == 9){
       block = new LBlock(1, board );
       if ( block->set() == false) { /* there isnt space to create the block */ }
    }else{
       block = new OBlock(1, board );
       if ( block->set() == false) { /* there isnt space to create the block */ }
    }
    return block;
}



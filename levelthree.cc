#include <cstdlib>
#include "levelthree.h"
#include "oblock.h"
#include "iblock.h"
#include "sblock.h"
#include "jblock.h"
#include "lblock.h"
#include "tblock.h"
#include "zblock.h"

class Board;

//constructor
LevelThree::LevelThree(): Level{3}{}


//destructor
LevelThree::~LevelThree(){

}

//get the Level number

const int LevelThree::getLevel(){

   return levelNumber;
}

//using random number to control the probability of
//which type of new block is generated
Block* LevelThree::nextBlock(Board* b){

   int rn = rand()%9; // rn in the range 0 to 8
   if(rn == 0 || rn == 7){
      Block* bl = new SBlock(b);
      return bl;
   }else if(rn == 1 || rn == 8){
      Block *bl = new ZBlock(b);
      return bl;
   }else if(rn == 2){
      Block *bl = new TBlock(b);
      return bl;
   }else if(rn == 3){
      Block *bl = new IBlock(b);
      return bl;
   }else if(rn == 4){
      Block *bl = new JBlock(b);
      return bl;
   }else if(rn == 5){
      Block *bl = new LBlock(b);
      return bl;
   }else{
      Block *bl = new OBlock(b);
      return bl;
   }
   
}



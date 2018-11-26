#include <stdlib.h>
#include "levelthree.h"



//constructor
LevelThree::LevelThree(){
   levelNumber = 3;
}


//destructor
LevelThree::~LevelThree(){

}

//get the Level number

const int LevelThree::getLevel(){

   return levelNumber;
}

//using random number to control the probability of
//which type of new block is generated
Block* LevelThree::nextBlock(){

   int rn = rand()%9; // rn in the range 0 to 8
   if(rn == 0 || rn == 7){
      Block* bl = new SBlock();
   }else if(rn == 1 || rn == 8){
      Block *bl = new ZBlock();
   }else if(rn == 2){
      Block *bl = new TBlock();
   }else if(rn == 3){
      Block *bl = new IBlock();
   }else if(rn == 4){
      Block *bl = new JBlock();
   }else if(rn == 5){
      Block *bl = new LBlock();
   }else{
      Block *bl = new OBlock();
   }
   
   return bl;
}



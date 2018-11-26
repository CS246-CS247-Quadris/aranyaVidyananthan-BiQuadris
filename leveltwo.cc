#include <stdlib.h>
#include "leveltwo.h"



//constructor
LevelTwo::LevelTwo(){
   levelNumber = 2;
}


//destructor
LevelTwo::~LevelTwo(){

}

//get the Level number

const int LevelTwo::getLevel(){

   return levelNumber;
}

//using random number to control the probability of
//which type of new block is generated
Block* LevelTwo::nextBlock(){

   int rn = rand()%7; // rn in the range 0 to 6
   if(rn == 0){
      Block* bl = new SBlock();
   }else if(rn == 1){
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



#include <stdlib.h>
#include "levelfour.h"



//constructor
LevelFour::LevelFour(){
   levelNumber = 4;
}


//destructor
LevelFour::~LevelFour(){

}

//get the Level number

const int LevelFour::getLevel(){

   return levelNumber;
}

//using random number to control the probability of
//which type of new block is generated
Block* LevelFour::nextBlock(){

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



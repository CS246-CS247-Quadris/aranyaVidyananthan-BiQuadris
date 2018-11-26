#include <stdlib.h>
#include "levelone.h"
#include "fstream.h"


//constructor
LevelOne::LevelOne(){
   levelNumber = 1;
}


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

   int rn = rand()%12; // rn in the range 0 to 11
   if(rn == 0){
      Block* bl = new SBlock();
   }else if(rn == 1){
      Block *bl = new ZBlock();
   }else if(rn == 2 || rn == 3){
      Block *bl = new TBlock();
   }else if(rn == 4 || rn == 5){
      Block *bl = new IBlock();
   }else if(rn == 6 || rn == 7){
      Block *bl = new JBlock();
   }else if(rn == 8 || rn == 9){
      Block *bl = new LBlock();
   }else{
      Block *bl = new OBlock();
   }
   
   return bl;
}



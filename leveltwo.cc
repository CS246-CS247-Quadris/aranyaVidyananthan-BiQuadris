#include <cstdlib>
#include <string>
#include "leveltwo.h"
#include "iblock.h"
#include "oblock.h"
#include "sblock.h"
#include "lblock.h"
#include "zblock.h"
#include "tblock.h"
#include "jblock.h"

using namespace std;

class Board;
//constructor
LevelTwo::LevelTwo(): Level{2}{}


//destructor
LevelTwo::~LevelTwo(){

}

//get the Level number

const int LevelTwo::getLevel(){

   return levelNumber;
}

//using random number to control the probability of
//which type of new block is generated
Block* LevelTwo::nextBlock(Board* b,string t){
   t = "...";
   int rn = rand()%7; // rn in the range 0 to 6
   if(rn == 0){
      Block* bl = new SBlock(b);
      return bl;
   }else if(rn == 1){
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



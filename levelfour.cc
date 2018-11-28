#include <cstdlib>
#include "levelfour.h"
#include "sblock.h"
#include "lblock.h"
#include "iblock.h"
#include "oblock.h"
#include "tblock.h"
#include "zblock.h"
#include "jblock.h"


class Board;
using namespace std;


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
Block* LevelFour::nextBlock(Board* b){

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



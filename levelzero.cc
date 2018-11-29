#include "levelzero.h"
#include "iblock.h"
#include "sblock.h"
#include "oblock.h"
#include "lblock.h"
#include "zblock.h"
#include "tblock.h"
#include "jblock.h"
#include "block.h"
class Board;

using namespace std;

//constructor
LevelZero::LevelZero(){
   levelNumber = 0;
}

//destructor

LevelZero::~LevelZero(){}

//make the virtual nextblock concrete

Block* LevelZero::nextBlock( Board * b){
   Block *bl = new IBlock( b );
   return bl;
}

//this is the method that actually does the work
Block* LevelZero::nextBlock(string blockName,Board * b){
   if(blockName == "S"){
      Block* bl = new SBlock(b);
      return bl;
   }else if(blockName == "I"){
      Block* bl = new IBlock(b);
      return bl;
   }else if(blockName == "L"){
      Block* bl = new LBlock(b);
      return bl;
   }else if(blockName == "Z"){
      Block* bl = new ZBlock(b);
      return bl;
   }else if(blockName == "J"){
      Block* bl = new JBlock(b);
      return bl;
   }else if(blockName == "T"){
      Block* bl = new TBlock(b);
      return bl;
   }else{
      Block* bl = new OBlock(b);
      return bl;
   }
   
}

const int LevelZero::getLevel(){
   return levelNumber;
}

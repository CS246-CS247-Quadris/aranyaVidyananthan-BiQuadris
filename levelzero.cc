#include "levelzero.h"


using namespace std;

//constructor
LevelZero::LevelZero(){
   levelNumber = 0;
}

//destructor

LevelZero::~LevelZero(){}

//make the virtual nextblock concrete

Block* LevelZero::nextBlock(){
   Block *bl = new IBlock();
   return bl;
}

//this is the method that actually does the work
Block* LevelZero::nextBlock(string blockName){
   if(blockName == "S"){
      Block* bl = new SBlock();
   }else if(blockName == "I"){
      Block* bl = new IBlock();
   }else if(blockName == "L"){
      Block* bl = new LBlock();
   }else if(blockName == "Z"){
      Block* bl = new ZBlock();
   }else if(blockName == "J"){
      Block* bl = new JBlock();
   }else if(blockName == "T"){
      Block* bl = new TBlock();
   }else{
      Block* bl = new OBlock();
   }
   return bl;
}

const int LevelZero::getLevel(){
   return levelNumber;
}

#include "level.h"
#include "block.h"
#include "iblock.h"

Level::Level( ){}


Level::~Level() {}

const int Level::getLevel(){
   return -1;
}

Block* Level::nextBlock(Board * b){
   return new IBlock(b);
}

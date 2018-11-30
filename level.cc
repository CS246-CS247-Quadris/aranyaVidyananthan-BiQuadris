#include "level.h"
#include "block.h"
#include "iblock.h"
#include <string>

using namespace std;

Level::Level( int levelnumber ): levelNumber{levelnumber}{}


Level::~Level() {}

const int Level::getLevel(){
   return -1;
}

Block* Level::nextBlock(Board * b, string t){
   return new IBlock(b);
}

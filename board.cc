#include <vector>
#include "board.h"
#include "block.h"
#include "cell.h"

using namespace std;

Board::Board(int player):player{player}{}

Board::~Board(){}

Block* Board::createBlock(){
   return level->nextBlock();
  
}

bool Board::rotateBlock(Block* b, int direction){

}

int Board::clearLines(){

}

void Board::setLevel(int l){
   if(l == 0){
 
   }else if(l == 1){

   }else if(l == 2){

   }else if(l == 3){

   }else if(l == 4){

   }
}

void Board::clearBoard(){

}

int Board::getLevel(){
   return level->getLevel();
}

void Board::detach(Block* b){

}

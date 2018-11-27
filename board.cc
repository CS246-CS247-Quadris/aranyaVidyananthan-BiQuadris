#include <vector>
#include "board.h"
#include "block.h"
#include "cell.h"
#include "levelone.h"
#include "levelzero.h"
#include "leveltwo.h"
#include "levelthree.h"
#include "levelfour.h"
#include "level.h"

using namespace std;

Board::Board(int player):player{player}{
   levelnum = 0;
   cells.resize(18); // 15+ 3 rows
   for(int i = 0; i < 18; i ++){
      for(int j = 0; j < 11; j ++){
         cells.push_back(Cell(j,i));// create empty cells
      }
   }
   
}
Board::~Board(){}

Block* Board::createBlock(){
   return level->nextBlock();
  
}

bool Board::rotateBlock(Block* b, int direction){

}

int Board::clearLines(){

}

void Board::setLevel(int l){
   levelnum = l;
   if(l == 0){
     level = new LevelZero(); 
   }else if(l == 1){
     level = new LevelOne();
   }else if(l == 2){
     level = new LevelTwo();
   }else if(l == 3){
     level = new LevelThree();
   }else if(l == 4){
     level = new LevelFour();
   }
}

void Board::clearBoard(){

}

int Board::getLevel(){
   return levelnum;
}

void Board::detach(Block* b){

}

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
    return true;
}

int Board::clearLines(){
    return 0;
}

void Board::setLevel(int l){
<<<<<<< HEAD
    if(l == 0){
 
    }else if(l == 1){

    }else if(l == 2){

    }else if(l == 3){

    }else if(l == 4){

    }
=======
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
>>>>>>> 00d152c3430003c65aff2dbad3d2493415be9734
}

void Board::clearBoard(){
    
}

int Board::getLevel(){
<<<<<<< HEAD
    return level->getLevel();
=======
   return levelnum;
>>>>>>> 00d152c3430003c65aff2dbad3d2493415be9734
}

void Board::detach(Block* b){

}

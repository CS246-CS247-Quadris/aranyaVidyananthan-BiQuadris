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
   cells.resize(11); // 11 columns
   for(int i = 0; i < 11; ++i){
       cells.resize(18); // 18 rows
      for(int j = 0; j < 18; ++j){
         cells[i].emplace_back(new Cell(i,j));// create empty cells
      }
   }
}


Board::~Board(){}


Block* Board::createBlock(){
    return level->nextBlock( this ); 
}


bool Board::rotateBlock(Block* b, int direction){
    return true;
}


int Board::clearLines(int i){
    return 0;
}

int Board::getScore(){
    return score;
}

Cell* Board::getCell(int i, int j){
   return cells[i][j];

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
   for (int i = 17; i >= 0; i --){
      bool row = true;
      for(int n = 0; n < 11; n ++){
         if(cells[n][i]->getStatus() == true){
            row = false;
            break;
         }
      }
      if(row){this->clearLines(i);}
   }     
}


int Board::getLevel(){
    return levelnum;
}


void Board::detach(Block* b){

}
/*
ostream & operator<< (ostream &out, const Board &b) {
   cout << "Level:   " << b.getLevel() << endl;
   cout << "Score:   " << b.getScore() << endl;
   cout << "-----------" << endl;
   for(int n = 0; n < 11; n ++){
      for(int i = 0; i < 18; i++){
         cout << b.getCell()->getType();
      }
      cout << endl;
   }
   cout << endl;
   //cout << *newblock << endl;
   return out;
}*/

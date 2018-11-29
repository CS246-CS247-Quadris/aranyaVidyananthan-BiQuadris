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



Board::Board(int player) {
    level = new LevelZero;
    levelnum = 0;
    player = player;
    cells.resize(11); // 11 columns
    for(int i = 0; i < 11; ++i){
        cells.resize(18); // 18 rows
        for(int j = 0; j < 18; ++j){
           cells[i].emplace_back(new Cell(i,j));// create empty cells
        }
    }
    Block * b = level->nextBlock( this );
    blocks.emplace_back( b ); // adds the currblock
    createBlock(); // creates the next block
}


Board::~Board(){
    for ( int n = 0; n < 11; ++n ) { cells[n].clear(); }
    cells.clear();
    cells.shrink_to_fit();
    //delete level;
}
 

// returns the current block
Block * Board::getCurrBlock() {
    return blocks.back();
}


//returns the next block
Block * Board::getNextBlock() {
    return nextBlock;
}


// creates a new block based on the level of the player
void Board::createBlock(){
    Block * b = level->nextBlock( this ); // creates a new block
    nextBlock = b;
}


// sets the next block to current and creates a new next block
bool Board::setNewBlock(){ // if it returns false the game is over
    Block * curr = nextBlock;
    blocks.emplace_back( curr ); 
    return curr->set(); // sets the curr block to the top of the board    
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

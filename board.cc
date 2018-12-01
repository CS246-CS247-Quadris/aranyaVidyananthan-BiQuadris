#include <vector>
#include <string>
#include "board.h"
#include "block.h"
#include "cell.h"
#include "levelone.h"
#include "levelzero.h"
#include "leveltwo.h"
#include "levelthree.h"
#include "levelfour.h"
#include "level.h"
#include <iostream>

using namespace std;


Board::Board( int player ):level{new LevelZero}, blocks{}, player{player}, 
    levelnum{0}, nextBlock{}, score{0} {
        cells.resize(11); // 11 columns
        for(int i = 0; i < 11; ++i){
            cells[i].resize(18); // 18 rows
            for(int j = 0; j < 18; ++j){
                cells[i][j] =  new Cell(i,j);// create empty cells
            }
        }
}


void Board::setFirstBlock(string t) {
    Block * b = level->nextBlock( this, t );
    blocks.emplace_back( b ); // adds the currblock
    b->set();
}


Board::~Board(){
    for ( int n = 0; n < 11; ++n ) { 
        cells[n].clear(); 
        cells[n].shrink_to_fit();  
    }
    cells.clear();
    cells.shrink_to_fit();
    delete level;
}
 

void Board::print() {
    for ( int i = 0; i < 18; ++i ) {
        for ( int n = 0; n < 11; ++n ) {
            cells[n][i]->print();
        }
    std::cout << '\n' << std::endl;
    }
    std::cout << '\n' << std::endl;
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
void Board::createBlock(string t){
    Block * b = level->nextBlock( this, t ); // creates a new block
    nextBlock = b;
}


// sets the next block to current and creates a new next block
bool Board::setNewBlock(){ // if it returns false the game is over
    Block * curr = nextBlock;
    blocks.emplace_back( curr );

    bool retval = curr->set(); // sets the curr block to the top of the board    
    if (retval == false) { delete curr; }
    return retval;
}


int Board::getPlayer() {
   return player;
}


void Board::clearLines(int i){
    int index = blocks.size()-1;
    for(int n = 0; n < index; n ++){
        blocks.at(n)->clearLine(i);
    }
}


int Board::getScore(){
    return score;
}


Cell * Board::getCell(int i, int j){
   return cells[i][j];
}


void Board::setLevel(int l){
    delete level;
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


int Board::clearBoard(){
   int lines = 0;
   for (int i = 17; i >= 0; i --){
      bool row = true;
      for(int n = 0; n < 11; n ++){
         if(cells[n][i]->getStatus() == true){
            row = false;
            break;
         }
      }
      if(row){
          this->clearLines(i);
          lines ++;
      }
   }
   return lines;     

}

void Board::updateScore(int lines){
    int s = (levelnum + lines)*(levelnum + lines);
    score += s;
}


int Board::getLevel(){
    return levelnum;
}



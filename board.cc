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
#include "window.h"

using namespace std;

const int scale = 17;


Board::Board( int player, int x, int y ):level{new LevelZero}, blocks{}, player{player}, 
    blind{false}, X{x}, Y{y}, levelnum{0}, nextBlock{}, score{0}, xw{nullptr} {
        cells.resize(11); // 11 columns
        for(int i = 0; i < 11; ++i){
            cells[i].resize(18); // 18 rows
            for(int j = 0; j < 18; ++j){
                cells[i][j] =  new Cell(i,j);// create empty cells
            }
        }
}

 
void Board::init( string t, Xwindow *display ) {
    xw = display;
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
    // delete blocks
    delete nextBlock;
    delete level;
}
 

void Board::print() {
    std::cout << "Level:    " << getLevel() << std::endl;
    std::cout << "Score:    " << getScore() << std::endl;
    std::cout << "-----------"  << std::endl;
    for ( int i = 0; i < 18; ++i ) {
        for ( int n = 0; n < 11; ++n ) {
            getCell(n,i)->print();
        }
    std::cout << '\n';
    }
    std::cout << "-----------" << std::endl;
    std::cout << "Next:      " << std::endl;
    getNextBlock()->print();
}


// returns the current block
Block * Board::getCurrBlock() {
    return blocks.back();
}


//returns the next block
Block * Board::getNextBlock() {
    return nextBlock;
}


bool Board::getBlind() {
    return blind;
}


void Board::setBlind( bool b ) {
    blind = b;
}


int Board::getX() {
    return X;
}


int Board::getY() {
    return Y;
}


Xwindow * Board::getDisplay() {
    return xw;
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
    xw->fillRectangle( (0 + X)*scale, (21 + Y)*scale, scale*29, scale*2, 0 );
    bool retval = curr->set(); // sets the curr block to the top of the board    
    if (retval == false) { delete curr; }
    return retval;
}


void Board::addScorefromBlock(int l){
    int s = (l+1)*(l+1);
    score += s;
    if ( player == 1 ) { 
        xw->fillRectangle( 170, 34, scale, scale, 0 );
        xw->drawString( 170, 34, to_string(score) );
    }
    else {
        xw->fillRectangle( 476, 34, scale, scale, 0 );
        xw->drawString( 476, 34, to_string(score) );
    }
}


int Board::getPlayer() {
   return player;
}


void Board::clearLines(int i){
    int index = blocks.size();
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
    if ( player == 1 ) {
        xw->fillRectangle( 166, 6, scale, scale, 0 );
        xw->drawString( 170, 17, to_string(levelnum) );
    }
    else {
        xw->fillRectangle( 470, 6, scale, scale, 0 );
        xw->drawString( 476, 17, to_string(levelnum) ); }
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
    if ( player == 1 ) {
        xw->fillRectangle( 166, 23, scale, scale, 0 );
        xw->drawString( 170, 34, to_string(score) );
    }
    else {
        xw->fillRectangle( 470, 23, scale, scale, 0 );
        xw->drawString( 476, 34, to_string(score) );
    }
}


int Board::getLevel(){
    return levelnum;
}



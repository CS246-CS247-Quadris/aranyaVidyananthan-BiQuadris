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
#include "iblock.h"
#include "lblock.h"
#include "oblock.h"
#include "jblock.h"
#include "tblock.h"
#include "zblock.h"
#include "sblock.h"

using namespace std;

const int scale = 17;


Board::Board(int player, int x, int y, int levelnumber): xw{nullptr}, blocks{}, 
    player{player}, blind{false}, X{x}, Y{y}, levelnum{levelnumber},nextBlock{}, score{0} {
        // if start level is supplied as a command line arg
        if (levelnumber == 0 ) { level = new LevelZero();}
        else if (levelnumber == 1) {level = new LevelOne();}
        else if (levelnumber == 2) {level = new LevelTwo();}
        else if (levelnumber == 3) {level = new LevelThree();}
        else {level = new LevelFour();}

        cells.resize(11); // 11 columns
        for(int i = 0; i < 11; ++i){
            cells[i].resize(18); // 18 rows
            for(int j = 0; j < 18; ++j){
                cells[i][j] =  new Cell(i,j);// create empty cells
            }
        }
}

 
void Board::init(string t, Xwindow *display) {
    xw = display;
    Block * b = level->nextBlock(this, t);
    blocks.emplace_back(b); // adds the currblock
    b->set();
}


Board::~Board(){
    for (int i = 0; i < 11; ++i) {
        for (int n = 0; n < 18; ++n) {
            delete cells[i][n];
        }
        cells[i].clear();
        cells[i].shrink_to_fit();
    }
    cells.clear();
    cells.shrink_to_fit();

    int length = blocks.size();
    for (int i = 0; i < length; ++i) {
        delete blocks[i];
    }
    blocks.clear();
    blocks.shrink_to_fit();
    delete level;
}
 

// clears the board and starts a new game
void Board::restart( int playernum, int a, int b, int levelnumber ) {
    for (int i = 0; i < 11; ++i) {
        for (int n = 0; n < 18; ++n) {
            delete cells[i][n];
        }
        cells[i].clear();
    }
    cells.clear();
    int length = blocks.size();
    for (int i = 0; i < length; ++i) {
        delete blocks[i];
    }
    blocks.clear();
    delete nextBlock;
    score = 0;
    xw = nullptr;

    cells.resize(11); // 11 columns
    for(int i = 0; i < 11; ++i){
        cells[i].resize(18); // 18 rows
        for(int j = 0; j < 18; ++j){
            cells[i][j] =  new Cell(i,j);// create empty cells
        }
    }
    player = playernum;
    blind = false;
    X = a;
    Y = b;
    levelnum = levelnumber;
    // if start level is supplied as a command line arg
    if (levelnumber == 0) {level = new LevelZero();}
    else if (levelnumber == 1) {level = new LevelOne();}
    else if (levelnumber == 2) {level = new LevelTwo();}
    else if (levelnumber == 3) {level = new LevelThree();}
    else {level = new LevelFour;}

}


void Board::print() {
    std::cout << "Level:    " << getLevel() << std::endl;
    std::cout << "Score:    " << getScore() << std::endl;
    std::cout << "-----------"  << std::endl;
    for (int i = 0; i < 18; ++i) {
        for (int n = 0; n < 11; ++n) {
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


// retuns of the board is blind for the player
bool Board::getBlind() {
    return blind;
}


// sets the board to blind
void Board::setBlind( bool b ) {
    blind = b;
}


// returns the x coordinate for the top left point of the board of the graphics
int Board::getX() {
    return X;
}


// returns the y coordinate for the top left point of the board for the graphics
int Board::getY() {
    return Y;
}


// returns the display
Xwindow * Board::getDisplay() {
    return xw;
}


// changes the current block to the type t
bool Board::changeCurrBlock(string t) {
    blocks.back()->clearBlock();
    delete blocks.back();
    Level * levelzero = new LevelZero();
    Block * b = levelzero->nextBlock(this, t);
    blocks.emplace_back(b);
    delete levelzero;
    bool retval = b->set();
    if (retval == false) {delete blocks.back();}
    return retval;
} 


// creates a new block based on the level of the player
void Board::createBlock(string t){
    nextBlock = level->nextBlock(this, t); // creates a new block
}


// sets the next block to current and creates a new next block
bool Board::setNewBlock(){ // if it returns false the game is over
    Block * curr = nextBlock;
    blocks.emplace_back(curr);
    if (xw) {xw->fillRectangle((0 + X)*scale, (21 + Y)*scale, scale*29, scale*2, 0);}
    bool retval = curr->set(); // sets the curr block to the top of the board    
    if (retval == false) { 
        blocks.pop_back();
        delete curr;
        curr = nullptr;
        nextBlock = nullptr;
    }
    return retval;
}


// adds to the score of the board
void Board::addScorefromBlock(int l){
    int s = (l+1)*(l+1);
    score += s;
    if (xw) {
        if (player == 1) { 
            xw->fillRectangle(170, 34, scale, scale, 0);
            xw->drawString(170, 34, to_string(score));
        }
        else {
            xw->fillRectangle(476, 34, scale, scale, 0);
            xw->drawString(476, 34, to_string(score));
        }
    }
}


// returns the player number of the board
int Board::getPlayer() {
   return player;
}


// clears the row i of the board
void Board::clearLines(int i){
    int index = blocks.size();
    for(int n = 0; n < index; n ++){
        blocks.at(n)->clearLine(i);
    }
}


// returns the score of the board
int Board::getScore(){
    return score;
}


// returns the cell at (i, j)
Cell * Board::getCell(int i, int j){
   return cells[i][j];
}


// sets the level of the board to l
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

    if (xw) {
        if (player == 1) {
            xw->fillRectangle(166, 6, scale, scale, 0);
            xw->drawString(170, 17, to_string(levelnum));
        }
        else {
            xw->fillRectangle(470, 6, scale, scale, 0);
            xw->drawString(476, 17, to_string(levelnum));
        }
    }
}


// checks if any of the rows are full and need to be cleared
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
          i ++;
      }
   }
   for (std::vector <Block *>::iterator it = blocks.begin() ; it < blocks.end(); ++it) {
       if ((*it)->getRemoved() == 4) {
           delete *it;
           blocks.erase( it );
       }
   }
   return lines; 
}


// updates the score of the board
void Board::updateScore(int lines){
    int s = (levelnum + lines)*(levelnum + lines);
    score += s;
    if (xw) {
        if (player == 1) {
            xw->fillRectangle(166, 23, scale, scale, 0);
            xw->drawString(170, 34, to_string(score));
        }
        else {
            xw->fillRectangle(470, 23, scale, scale, 0);
            xw->drawString(476, 34, to_string(score));
        }
    }
}


int Board::getLevel(){
    return levelnum;
}



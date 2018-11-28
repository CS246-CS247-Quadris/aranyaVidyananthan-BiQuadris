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


Board::Board(int player):player{player}, level{new LevelZero()}, nextblock{}{
    levelnum = 0;
    cells.resize(11); // 11 columns
    for(int i = 0; i < 11; ++i){
        cells.resize(18); // 18 rows
        for(int j = 0; j < 18; ++j){
           cells[i].emplace_back(Cell(i,j));// create empty cells
        }
    }
}


Board::~Board(){
    for ( int n = 0; n < 11; ++n ) { cells[n].clear(); }
    cells.clear();
    cells.shrink_to_fit();
    delete level;
}


Block* Board::createBlock(){
    Block * b = level->nextBlock( this ); // creates a new block
    blocks.emplace_back( b );
    return b;
}


bool Board::rotateBlock(Block* b, int direction){
    b->rotate( direction );
}


int Board::clearLine( int rownumber ){
    
}

Cell* Board::getCell(int i, int j){
   return &cells[i][j];

}

void Board::setLevel(int l){
    levelnum = l;
    delete level;
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
    for ( int i = 17; i >= 0 ; --i ) {
        bool row = true;
        for ( int n = 0; n < 11; ++n ) {
            if ( cells[n][i].getStatus() == true ) { 
                 row = false;
                 break;
            }    
        }
        if ( row == true ) { clearLine( i ); }
    }   
}


int Board::getLevel(){
    return levelnum;
}


void Board::detach(Block* b){
    
}


ostream & operator<< ( ostream &out, const Board & b ) {
    std::cout << "Level:    " << b.levelnum << std::endl;
    std::cout << "Score:    " << b.score << std::endl;
    std::cout << "-----------" << std::endl;
    for ( int n = 0; n < 11; ++n ) {
        for ( int i = 0; i < 18; ++i ) {
             std::cout << b.cells[n][i].getType();
        }
    std::endl;
    }
    std::endl;
    std::cout << *newblock << std::endl;
    return out;
}

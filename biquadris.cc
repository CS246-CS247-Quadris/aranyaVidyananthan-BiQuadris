#include <ostream>
#include "biquadris.h"
#include "board.h"
#include <iostream>
#include <string>
#include "window.h"

using namespace std;

//constructor
Biquadris::Biquadris( int level, bool graphics ): boardOne{new Board( 1, 0, 3, level )}, 
    boardTwo{ new Board( 2, 18, 3, level )}, ScoreOne{0}, ScoreTwo{0}, currplayer{1}, display{nullptr} {
    if ( graphics ) { 
        display = new Xwindow ( 493, 442 );
        display->drawString( 0, 17, "Level:");
        display->drawString( 170, 17, to_string(level) );
        display->drawString( 0, 34, "Score:");
        display->drawString( 170, 34, "0" );
        display->drawString( 306, 17, "Level:");
        display->drawString( 476, 17, to_string(level) );
        display->drawString( 306, 34, "Score:");
        display->drawString( 476, 34, "0" );
        display->drawString( 0, 391, "Next:" );
        display->drawString( 306, 391, "Next:" );
    }   
}


//destructor
Biquadris::~Biquadris(){
    delete boardOne;
    delete boardTwo;
    delete display;
}


// initializes boards with the first blocks
void Biquadris::setFirstBlocks(string t1,string t2){
    boardOne->init( t1, display );
    boardTwo->init( t2, display );
}


// restarts the game board
void Biquadris::restart( int level = 0, bool graphics = true ) {
    boardOne->restart(1, 0, 3, level );
    boardTwo->restart(2, 18, 3, level );
    ScoreOne = 0;
    ScoreTwo = 0;
    currplayer = 1;
    if ( display ) { delete display; }
    display = nullptr;
    if ( graphics ) {
        display = new Xwindow ( 493, 442 );
        display->drawString( 0, 17, "Level:");
        display->drawString( 170, 17, "0" );
        display->drawString( 0, 34, "Score:");
        display->drawString( 170, 34, "0" );
        display->drawString( 306, 17, "Level:");
        display->drawString( 476, 17,  "0");
        display->drawString( 306, 34, "Score:");
        display->drawString( 476, 34, "0" );
        display->drawString( 0, 391, "Next:" );
        display->drawString( 306, 391, "Next:" );
    }
}


// changes the new high score of the game
void Biquadris::newHigh(){
    if(currplayer == 1){
        if(ScoreOne < boardTwo->getScore()){
            ScoreOne = boardOne->getScore();
        }
    }else{
        if(ScoreTwo < boardTwo->getScore()){
            ScoreTwo = boardTwo->getScore();
        }
    }
}


// returns the current board being played
Board * Biquadris::getCurrPlayer() {
    if ( currplayer == 1 ) {
         return boardOne; 
    }
    return boardTwo;
}


// switches the board being played
void Biquadris::switchPlayer() {
    if ( currplayer == 1 ) { currplayer = 2; }
    else { currplayer = 1; }
}


void Biquadris::print() {
    std::cout << "Hi Score: " << ScoreOne << "       " << "Hi Score  " << ScoreTwo << std::endl;
    std::cout << "Level:    " << boardOne->getLevel() << "       " << "Level:    " << boardTwo->getLevel() << std::endl;
    std::cout << "Score:    " << boardOne->getScore() << "       " << "Score:    " << boardTwo->getScore() << std::endl;
    std::cout << "-----------       -----------" << std::endl;
    for ( int i = 0; i < 18; ++i ) { // row number
        for ( int n = 0; n < 11; ++n ) { // column number
            // checks if player ones board is blind
            if ( boardOne->getBlind() == true && n >= 2 && n <= 8 && i >= 2 && i <= 11 ) {
                std::cout << "?";
            }
            else {
                boardOne->getCell(n,i)->print();
            }
        }
        std::cout << "       ";
        for ( int n = 0; n < 11; ++n ) {
            // checks if player twos board is blind
            if ( boardTwo->getBlind() == true && n >= 2 && n <= 8 && i >= 2 && i <= 11 ) {
                std::cout << "?";
            }
            else {
                boardTwo->getCell(n,i)->print();
            }
        }
    std::cout << '\n';
    }
    std::cout << "-----------       -----------" << std::endl;
    std::cout << "Next:      " << "       " << "Next:      " << std::endl;
    getCurrPlayer()->getNextBlock()->print();
}



#include <ostream>
#include "biquadris.h"
#include "board.h"
#include <iostream>
#include <string>
#include "window.h"

using namespace std;

//constructor
Biquadris::Biquadris(): boardOne{new Board( 1, 0, 3 )}, 
    boardTwo{new Board( 2, 18, 3)}, ScoreOne{0}, ScoreTwo{0}, currplayer{1}, display{new Xwindow( 493, 425 )}{}


//destructor
Biquadris::~Biquadris(){}

void Biquadris::setFirstBlocks(string t1,string t2){
    boardOne->init( t1, display );
    boardTwo->init( t2, display );
}

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

Board * Biquadris::getCurrPlayer() {
    if ( currplayer == 1 ) {
         return boardOne; 
    }
    return boardTwo;
}


void Biquadris::switchPlayer() {
    if ( currplayer == 1 ) { currplayer = 2; }
    else { currplayer = 1; }
}

int Biquadris::playerNum(){
    return currplayer;
}

void Biquadris::print() {
    std::cout << "Hi Score: " << ScoreOne << "       " << "Hi Score  " << ScoreTwo << std::endl;
    std::cout << "Level:    " << boardOne->getLevel() << "       " << "Level:    " << boardTwo->getLevel() << std::endl;
    std::cout << "Score:    " << boardOne->getScore() << "       " << "Score:    " << boardTwo->getScore() << std::endl;
    std::cout << "-----------       -----------" << std::endl;
    for ( int i = 0; i < 18; ++i ) {
        for ( int n = 0; n < 11; ++n ) {
            boardOne->getCell(n,i)->print();
        }
        std::cout << "       ";
        for ( int n = 0; n < 11; ++n ) {
            boardTwo->getCell(n,i)->print();
        }
    std::cout << '\n';
    }
    std::cout << "-----------       -----------" << std::endl;
    std::cout << "Next:      " << "       " << "Next:      " << std::endl;
    getCurrPlayer()->getNextBlock()->print();
}



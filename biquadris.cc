#include <ostream>
#include "biquadris.h"
#include "board.h"
#include <iostream>
#include <string>

using namespace std;

//constructor
Biquadris::Biquadris(): boardOne{new Board(1)}, 
    boardTwo{new Board(2)}, ScoreOne{0}, ScoreTwo{0}, currplayer{1}{
}


//destructor
Biquadris::~Biquadris(){}

void Biquadris::setFirstBlocks(string t1,string t2){
    boardOne->setFirstBlock(t1);
    boardTwo->setFirstBlock(t2);
}


Board * Biquadris::getCurrPlayer() {
    if ( currplayer == 1 ) { return boardOne; }
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
    for ( int i = 0; i < 18; ++i ) {
        for ( int n = 0; n < 11; ++n ) {
            boardOne->getCell(n,i)->print();
        }
    std::cout << '\n' << std::endl;
    }
    std::cout << '\n' << std::endl;
    for ( int i = 0; i < 18; ++i ) {
        for ( int n = 0; n < 11; ++n ) {
            boardTwo->getCell(n,i)->print();
        }
    std::cout << '\n' << std::endl;
    }
    std::cout << '\n' << std::endl;
}

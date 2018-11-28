#include <ostream>
#include "biquadris.h"
#include "board.h"

//constructor
Biquadris::Biquadris(): boardOne{new Board(1)}, 
    boardTwo{new Board(2)}, ScoreOne{0}, ScoreTwo{0}, currplayer{1}{}


//destructor
Biquadris::~Biquadris(){}


Board * Biquadris::getCurrPlayer() {
    if ( currplayer == 1 ) { return boardOne; }
    return boardTwo;
}


void Biquadris::switchPlayer() {
    if ( currplayer == 1 ) { currplayer = 2; }
    else { currplayer = 1; }
}


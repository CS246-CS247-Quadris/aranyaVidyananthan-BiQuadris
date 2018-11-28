#include <ostream>
#include "biquadris.h"
#include "board.h"


//ctor
Biquadris::Biquadris(){
   boardOne = new Board(1);
   boardTwo = new Board(2);
   ScoreOne = 0;
   ScoreTwo = 0;
}

//dtor

Biquadris::~Biquadris(){
}

void Biquadris::ClearBoards(){


}

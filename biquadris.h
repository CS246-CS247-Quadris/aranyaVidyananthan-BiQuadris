#ifndef _BIQUADRIS_H
#define _BIQUADRIS_H
#include<string>
#include <cstdlib>
#include "window.h"


using namespace std;

class Board;

class Biquadris{
protected:
    Board* boardOne;
    Board* boardTwo;
    int ScoreOne;
    int ScoreTwo;
    int currplayer;
    Xwindow *display;

public:
    Biquadris( int level = 0, bool graphics = true );
    ~Biquadris();
    // clears and restarts the game board
    void restart( int level, bool graphics );
    // returns the cureent board being played
    Board * getCurrPlayer();
    // switched the board being played on
    void switchPlayer();
    // prints the board
    void print();
    // initializes the boards with the first blocks
    void setFirstBlocks(string t1, string t2);
    // changes the new high score of the game
    void newHigh();
};

#endif

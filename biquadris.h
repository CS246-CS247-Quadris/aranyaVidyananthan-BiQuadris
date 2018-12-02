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
    Biquadris();
    ~Biquadris();
    Board * getCurrPlayer();
    void switchPlayer();
    void print();
    void setFirstBlocks(string t1, string t2);
    int playerNum();
    void newHigh();
};

#endif

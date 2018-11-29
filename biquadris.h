#ifndef _BIQUADRIS_H
#define _BIQUADRIS_H
#include <cstdlib>

class Board;

class Biquadris{
protected:
    Board* boardOne;
    Board* boardTwo;
    int ScoreOne;
    int ScoreTwo;
    int currplayer;

public:
    Biquadris();
    ~Biquadris();
    Board * getCurrPlayer();
    void switchPlayer();
    void print();
    void setFirstBlocks();
};

#endif

#ifndef _BIQUADRIS_H
#define _BIQUADRIS_H
#include<string>
#include <cstdlib>
using namespace std;

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
    void setFirstBlocks(string t1, string t2);
    int playerNum();
    void newHigh();
};

#endif

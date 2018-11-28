#ifndef _BIQUADRIS_H
#define _BIQUADRIS_H

#include <cstdlib>
class Board;

//using namespace std;

class Biquadris{
protected:
    Board* boardOne;
    Board* boardTwo;
    int ScoreOne;
    int ScoreTwo;

public:
    Biquadris();
    ~Biquadris();
    void ClearBoards();

};

#endif

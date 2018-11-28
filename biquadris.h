#ifndef _BIQUADRIS_H
#define _BIQUADRIS_H

class Board;

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

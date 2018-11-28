#ifndef _LEVEL_H
#define _LEVEL_H

using namespace std;

class Block;
class Board;

class Level{
protected:
    int levelNumber;
    Board * board;

public:
    Level( int levelnumber, Board * board );
    ~Level();
    virtual Block* nextBlock()=0;
    virtual const int getLevel()=0;

};

#endif

#ifndef _LEVEL_H
#define _LEVEL_H

using namespace std;

class Block;
class Board;

class Level{
protected:
    int levelNumber;

public:
    Level( );
    ~Level();
    virtual Block* nextBlock( Board * board )=0;
    virtual const int getLevel()=0;

};

#endif

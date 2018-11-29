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
    virtual Block* nextBlock( Board * board );
    virtual const int getLevel();

};


#endif

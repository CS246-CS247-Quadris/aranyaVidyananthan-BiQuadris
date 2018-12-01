#ifndef _LEVEL_H
#define _LEVEL_H
#include "block.h"

using namespace std;

class Board;

class Level{
protected:
    int levelNumber;

public:
    Level( int levelnumber );
    virtual ~Level();
    virtual Block* nextBlock( Board * board );
    virtual const int getLevel();

};


#endif

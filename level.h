#ifndef _LEVEL_H
#define _LEVEL_H
#include "block.h"
#include <string>


using namespace std;

class Board;

class Level{
protected:
    int levelNumber;

public:
    Level( int levelnumber );
    virtual ~Level();
    virtual Block* nextBlock( Board * board, string t );
    virtual const int getLevel();

};


#endif

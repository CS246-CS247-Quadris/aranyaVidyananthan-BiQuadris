#ifndef _LEVEL_H
#define _LEVEL_H
#include "block.h"

using namespace std;

class Level{
protected:
    int levelNumber;

public:
    Level();
    ~Level();
    virtual Block* nextBlock()=0;
    virtual const int getLevel()=0;

};

#endif

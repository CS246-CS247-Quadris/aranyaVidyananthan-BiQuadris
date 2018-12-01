#ifndef _LEVELONE_H
#define _LEVELONE_H
#include "level.h"

class Board;

using namespace std;

class LevelOne : public Level{   
public:
    LevelOne();
    ~LevelOne();
    Block* nextBlock( Board * board, string t ) override;
    const int getLevel()override;

};

#endif

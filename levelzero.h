#ifndef _LEVELZERO_H
#define _LEVELZERO_H
#include <string>
#include "level.h"


class Board;

class LevelZero : public Level{    
public:
    LevelZero();
    ~LevelZero();
    Block* nextBlock( Board * b )override;
    Block* nextBlock(string blockName, Board *b);
    const int getLevel()override;
};

#endif

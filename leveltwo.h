#ifndef _LEVELTWO_H
#define _LEVELTWO_H
#include "level.h"

class Block;
class Board;

using namespace std;

class LevelTwo : public Level{
public:
    LevelTwo();
    ~LevelTwo();
    Block* nextBlock( Board * board )override;
    const int getLevel()override;
};

#endif

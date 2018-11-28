#ifndef _LEVELFOUR_H
#define _LEVELFOUR_H
#include "level.h"

class Block;
class Board;

using namespace std;

class LevelFour : public Level{
public:
    LevelFour();
    ~LevelFour();
    Block* nextBlock( Board * board ) override;
    const int getLevel() override;
};
#endif

#ifndef _BOARD_H
#define _BOARD_H
#include "board.h"
#include "cell.h"
#include "level.h"

class Block;

using namespace std;

class Board{
protected:
    std::vector< std::vector< Cell > > cells;
    Level *level;
    std::vector< Block* > blocks;
    int player;

public:
    Board(int player);
    ~Board();
    Block* createBlock();
    bool rotateBlock(Block* b, int direction);
    int clearLines();
    void setLevel(int l);
    void clearBoard();
    int getLevel();
    void detach(Block* b);
};

#endif

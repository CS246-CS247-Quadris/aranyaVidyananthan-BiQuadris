#ifndef _BOARD_H
#define _BOARD_H
#include <vector>
#include "board.h"
#include "cell.h"
#include "level.h"


class Block;

using namespace std;

class Board{
protected:
<<<<<<< HEAD
    Block * currblock;
    vector<vector<Cell>> cells;
=======
    vector<vector<Cell*>> cells;
>>>>>>> c469de1aa24eaa17dd8d2e9ca2775dfcfa56bd8f
    Level *level;
    vector<Block*> blocks;
    int player;
    int levelnum;
   
public:
    Board(int player);
    Cell* getCell(int i, int j);
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

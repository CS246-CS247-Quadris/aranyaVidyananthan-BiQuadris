#ifndef _BOARD_H
#define _BOARD_H
#include <vector>
#include <string>
#include "cell.h"
#include "level.h"
using namespace std;

class Block;

class Board{
protected:
    std::vector< std::vector < Cell * > > cells;
    Level *level;
    std::vector< Block * > blocks;
    int player;
    int levelnum;
    Block* nextBlock;
    int score;
   
public:
    Board(int player);
    ~Board();

    Block * getNextBlock();
    Block * getCurrBlock();
    bool setNewBlock();
    Cell* getCell(int i, int j);
    void createBlock(string t);
    int clearLines(int i);
    void setLevel(int l);
    void clearBoard();
    int getLevel();
    int getScore();
    int getPlayer();
    void detach(Block* b);
    void print();
    void setFirstBlock(string t);
};

#endif

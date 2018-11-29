#ifndef _BOARD_H
#define _BOARD_H
#include <ostream>
#include <vector>
#include "board.h"
#include "cell.h"
#include "level.h"

class Block;

using namespace std;

class Board{
protected:
    Block * nextblock;
    vector< vector < Cell * > > cells;
    Level *level;
    vector< Block* > blocks;
    int player;
    int levelnum;
    Block* nextBlock = nullptr;
    int score = 0;
   
public:
    Board(int player);
    ~Board();

    Block * getNextBlock();
    Block * getCurrBlock();
    bool setNewBlock();
    Cell* getCell(int i, int j);
    void createBlock();
    int clearLines(int i);
    void setLevel(int l);
    void clearBoard();
    int getLevel();
    int getScore();
    void detach(Block* b);

};

//ostream & Board::operator<<( ostream &out, const Board &b)
#endif

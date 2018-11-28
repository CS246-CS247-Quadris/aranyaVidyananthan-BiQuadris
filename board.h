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
    Block * nextblock;
    vector< vector < Cell * > > cells;
    Level *level;
    vector< Block* > blocks;
    int player;
    int levelnum;
   
public:
    Board(int player);
    Cell* getCell(int i, int j);
    ~Board();
    Block* createBlock();
    bool rotateBlock(Block* b, int direction);
    int clearLine( int rownumber );
    void setLevel(int l);
    void clearBoard();
    int getLevel();
    void detach(Block* b);

};

ostream & Board::operator<<( ostream &out, const Board & b )

#endif

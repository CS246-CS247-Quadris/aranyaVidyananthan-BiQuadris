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

<<<<<<< HEAD
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
=======
   vector<vector<Cell>> cells;
   Level *level;
   vector<Block*> blocks;
   int player;
   int levelnum;
   
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
>>>>>>> 00d152c3430003c65aff2dbad3d2493415be9734
};

#endif

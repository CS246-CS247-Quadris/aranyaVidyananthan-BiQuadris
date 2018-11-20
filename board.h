#ifndef _BOARD_H
#define _BOARD_H

using namespace std;

class Board{

   vector<vector<Cell>> cells;
   Level level;
   vector<Block*> blocks;

   public:
   Board();
   ~Board();
   Block* createBlock();
   bool rotateBlock(Block* b, int direction);
   int clearLines();
   void clearBoard();
   int getLevel();
   void detach(Block* b);
};

#endif

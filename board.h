#ifndef _BOARD_H
#define _BOARD_H

using namespace std;

class Board{

   vector<vector<Cell>> cells;
   Level level;
   vector<Block*> blocks;
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

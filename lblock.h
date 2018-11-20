#ifndef _LBLOCK_H
#define _LBLOCK_H

using namespace std;

class LBlock : public Block{

   public:
   LBlock();
   ~LBlock();
   bool move(int direction)override;
   const char getType()override;
   bool rotate(int direction)override;
   void attachCell(Cell* c)override;
   void detachCell(Cell* c)override;
};

#endif

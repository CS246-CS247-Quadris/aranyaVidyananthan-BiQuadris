#ifndef _SBLOCK_H
#define _SBLOCK_H

using namespace std;

class SBlock : public Block{

   public:
   SBlock();
   ~SBlock();
   bool move(int direction)override;
   const char getType()override;
   bool rotate(int direction)override;
   void attachCell(Cell* c)override;
   void detachCell(Cell* c)override;
};

#endif

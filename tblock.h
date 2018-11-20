#ifndef _TBLOCK_H
#define _TBLOCK_H

using namespace std;

class TBlock : public Block{

   public:
   TBlock();
   ~TBlock();
   bool move(int direction)override;
   const char getType()override;
   bool rotate(int direction)override;
   void attachCell(Cell* c)override;
   void detachCell(Cell* c)override;
};

#endif

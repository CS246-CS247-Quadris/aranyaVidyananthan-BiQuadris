#ifndef _IBLOCK_H
#define _IBLOCK_H

using namespace std;

class IBlock : public Block{

   public:
   IBlock();
   ~IBlock();
   bool move(int direction)override;
   const char getType()override;
   bool rotate(int direction)override;
   void attachCell(Cell* c)override;
   void detachCell(Cell* c)override;
};

#endif

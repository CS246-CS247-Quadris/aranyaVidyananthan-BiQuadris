#ifndef _OBLOCK_H
#define _OBLOCK_H

using namespace std;

class OBlock : public Block{

   public:
   OBlock();
   ~OBlock();
   bool move(int direction)override;
   const char getType()override;
   bool rotate(int direction)override;
   void attachCell(Cell* c)override;
   void detachCell(Cell* c)override;
};

#endif

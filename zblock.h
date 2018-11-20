#ifndef _ZBLOCK_H
#define _ZBLOCK_H

using namespace std;

class ZBlock : public Block{

   public:
   ZBlock();
   ~ZBlock();
   bool move(int direction)override;
   const char getType()override;
   bool rotate(int direction)override;
   void attachCell(Cell* c)override;
   void detachCell(Cell* c)override;
};

#endif

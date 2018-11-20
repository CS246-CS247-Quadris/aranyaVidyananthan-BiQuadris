#ifndef _JBLOCK_H
#define _JBLOCK_H

using namespace std;

class JBlock : public Block{

   public:
   JBlock();
   ~JBlock();
   bool move(int direction)override;
   const char getType()override;
   bool rotate(int direction)override;
   void attachCell(Cell* c)override;
   void detachCell(Cell* c)override;
};

#endif

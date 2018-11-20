#ifndef _BLOCK_H
#define _BLOCK_H
#include <vector>

using namespace std;

class Block{

   vector<Cell* >shape;
   vector<Cell* >temp;
   char type;
   int orientation;
   Board *g;
   int removed;
 
   public:
   virtual Block();
   virtual ~Block();
   virtual bool move(int direction)=0;
   virtual bool rotate(int direction)=0;
   virtual const char getType()=0;
   virtual void attachCell(Cell* c)=0;
   virtual void detachCell(Cell* c)=0;
};

#endif

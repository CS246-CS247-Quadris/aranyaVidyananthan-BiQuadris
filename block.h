#ifndef _BLOCK_H
#define _BLOCK_H
#include <vector>
#include "board.h"

using namespace std;

class Block{
   protected:
   vector< Cell* >shape;
   vector< Cell* >temp;
   char type;
   int orientation;
   Board *g;
   int removed;
 
public:
   virtual Block( char type );
   virtual ~Block();
   virtual bool set()=0;
   virtual bool move(int direction)=0;
   virtual bool rotate(int direction)=0;
   virtual const char getType()=0;

};

#endif

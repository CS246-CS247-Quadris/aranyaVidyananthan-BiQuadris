#ifndef _BOARD_H
#define _BOARD_H

using namespace std;

class Level{

   int levelNumber;

   public:
   virtual Level();
   virtual ~Level();
   virtual Block* nextBlock()=0;
   virtual const int getLevel()=0;

};

#endif

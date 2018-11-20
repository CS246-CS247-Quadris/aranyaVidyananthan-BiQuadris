#ifndef _CELL_H
#define _CELL_H

using namespace std;

class Cell{

   bool isempty;
   char t;
   int x;
   int y;

   public:
   const char getType();
   void setType();
   bool getStatus();
   void setStatus();
   const int getX();
   const int getY();
};

#endif

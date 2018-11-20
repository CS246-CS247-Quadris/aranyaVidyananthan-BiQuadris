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
   void setType( char type );
   bool getStatus();
   void setStatus( bool status );
   const int getX();
   const int getY();
};

#endif

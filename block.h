#ifndef _BLOCK_H
#define _BLOCK_H
#include <vector>

class Cell;
class Board;

class Block {
protected:
    std::vector< Cell* >shape;
    std::vector< Cell* >temp;
    char type;
    int orientation;
    Board *g;
    int removed;
 
public:
    Block( char type, Board * g );
    virtual~Block();
    virtual bool set()=0;
    virtual bool move(int direction)=0;
    virtual bool rotate(int direction)=0;
    virtual const char getType()=0;
    virtual void print() = 0; 
};

#endif

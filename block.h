#ifndef _BLOCK_H
#define _BLOCK_H
#include <vector>


class Cell;
class Board;

class Block {
protected:
    std::vector< Cell* >shape;
    std::vector< Cell* >temp;
    int levelcreated;
    char type;
    int orientation;
    Board *g;
    int removed;
    const int scale;
 
    virtual const char getType()=0;
public:
    Block( int levelcreated,char type, Board * g );
    virtual~Block();
    virtual bool set()=0;
    virtual bool move(int direction)=0;
    virtual bool rotate(int direction)=0;
    virtual void print()=0; 
    void clearLine(int rowNum);
    void clearBlock();
};

#endif

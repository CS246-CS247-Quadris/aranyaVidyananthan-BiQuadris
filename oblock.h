#ifndef _OBLOCK_H
#define _OBLOCK_H
#include "block.h"
#include <iostream>

class OBlock : public Block{

public:
    OBlock(int level, Board * g );
    ~OBlock();

    // sets the block in its first pos, true if successful
    bool set() override;
    // moves the block one point to the left, right or down, return true if successful
    bool move( int direction ) override;
    // returns the type of the block
    const char getType() override;
    // rotates the block one turn clockwise or counterclockwise, return true if successful
    bool rotate( int direction ) override;
    void print();
};


#endif

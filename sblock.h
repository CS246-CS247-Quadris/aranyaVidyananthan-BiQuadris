#ifndef _SBLOCK_H
#define _SBLOCK_H
#include "block.h"
#include <iostream>

class SBlock : public Block{

public:
    SBlock(int level, Board * g );
    ~SBlock();

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

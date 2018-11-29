#ifndef _LBLOCK_H
#define _LBLOCK_H
#include "block.h"
#include <iostream>

class LBlock : public Block{

public:
    LBlock( Board * g );
    ~LBlock();
 
    // sets the block in its first pos, true if successful
    bool set() override;
    // moves the block one point to the left, right or down, return true if successful
    bool move( int direction ) override;
    // returns the type of the block
    const char getType() override;
    // rotates the block one turn clockwise or counterclockwise, return true if successful
    bool rotate( int direction ) override;

};

std::ostream & operator<<( std::ostream & out, Lblock block );

#endif

#ifndef _TBLOCK_H
#define _TBLOCK_H
#include "block.h"
#include <iostream>

class TBlock : public Block{

public:
    TBlock( Board * g );
    ~TBlock();

    // sets the block in its first pos, true if successful
    bool set() override;
    // moves the block one point to the left, right or down, return true if successful
    bool move( int direction ) override;
    // returns the type of the block
    const char getType() override;
    // rotates the block one turn clockwise or counterclockwise, return true if successful
    bool rotate( int direction ) override;

};

std::ostream & operator<<( std::ostream & out, TBlock block );

#endif

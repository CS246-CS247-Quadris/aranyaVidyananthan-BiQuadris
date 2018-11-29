#include "block.h"


Block::Block( char type, Board * g ):shape{}, 
    temp{}, type{type}, orientation{1}, g{g}, removed{0}{}

Block::~Block() {}

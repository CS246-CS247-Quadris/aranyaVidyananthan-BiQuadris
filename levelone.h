#ifndef _LEVELONE_H
#define _LEVELONE_H
#include "level.h"

using namespace std;

class LevelOne : public Level{
   
public:
   LevelOne( Board * board );
   ~LevelOne();
   Block* nextBlock()override;
   const int getLevel()override;
};
#endif

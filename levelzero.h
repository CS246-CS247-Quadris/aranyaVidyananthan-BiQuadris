#ifndef _LEVELZERO_H
#define _LEVELZERO_H

using namespace std;

class LevelZero : public Level{
   
   public:
   LevelZero();
   ~LevelZero();
   Block* nextBlock()override;
   const int getLevel()override;
};
#endif

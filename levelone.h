#ifndef _LEVELONE_H
#define _LEVELONE_H

using namespace std;

class LevelOne : public Level{
   
   public:
   LevelOne();
   ~LevelOne();
   Block* nextBlock()override;
   const int getLevel()override;
};
#endif

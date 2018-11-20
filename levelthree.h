#ifndef _LEVELTHREE_H
#define _LEVELTHREE_H

using namespace std;

class LevelThree : public Level{
   
   public:
   LevelThree();
   ~LevelThree();
   Block* nextBlock()override;
   const int getLevel()override;
};
#endif

#ifndef _LEVELTWO_H
#define _LEVELTWO_H

using namespace std;

class LevelTwo : public Level{
   
   public:
   LevelTwo();
   ~LevelTwo();
   Block* nextBlock()override;
   const int getLevel()override;
};
#endif

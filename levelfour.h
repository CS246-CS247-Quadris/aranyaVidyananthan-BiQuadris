#ifndef _LEVELFOUR_H
#define _LEVELFOUR_H

using namespace std;

class LevelFour : public Level{
   
   public:
   LevelFour();
   ~LevelFour();
   Block* nextBlock()override;
   const int getLevel()override;
};
#endif

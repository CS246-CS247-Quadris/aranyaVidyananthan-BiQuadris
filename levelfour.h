#ifndef _LEVELFOUR_H
#define _LEVELFOUR_H

class Board;

using namespace std;

class LevelFour : public Level{
public:
    LevelFour();
    ~LevelFour();
    Block* nextBlock( Board * board ) override;
    const int getLevel() override;
};
#endif

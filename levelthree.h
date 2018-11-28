#ifndef _LEVELTHREE_H
#define _LEVELTHREE_H

class Board;

using namespace std;

class LevelThree : public Level{
public:
    LevelThree();
    ~LevelThree();
    Block* nextBlock( Board * board )override;
    const int getLevel()override;
};

#endif

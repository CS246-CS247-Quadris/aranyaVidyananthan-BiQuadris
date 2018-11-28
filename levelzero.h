#ifndef _LEVELZERO_H
#define _LEVELZERO_H

class Board;

class LevelZero : public Level{    
public:
    LevelZero();
    ~LevelZero();
    Block* nextBlock( Board * board )override;
    Block* nextBlock(string blockName);
    const int getLevel()override;
};

#endif

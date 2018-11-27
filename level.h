#ifndef _BOARD_H
#define _BOARD_H

using namespace std;

class Level{
protected:
    int levelNumber;

public:
    Level();
    ~Level();
    virtual Block* nextBlock()=0;
    virtual const int getLevel()=0;

};

#endif

#ifndef _LEVEL_H
#define _LEVEL_H
<<<<<<< HEAD
#include "block.h"
=======
#include <string>
>>>>>>> a251e8eab561807167f1521e46f5e72ed71a4056

using namespace std;

class Board;

class Level{
protected:
    int levelNumber;

public:
    Level( int levelnumber );
    virtual ~Level();
    virtual Block* nextBlock( Board * board, string t );
    virtual const int getLevel();

};


#endif

#ifndef _BOARD_H
#define _BOARD_H
#include <vector>
#include <string>
#include "cell.h"
#include "level.h"
using namespace std;

class Block;

class Board{
protected:
    std::vector< std::vector < Cell * > > cells;
    Level *level;
    std::vector< Block * > blocks;
    int player;
    int levelnum;
    Block* nextBlock;
    int score;
  
    int clearLines(int i); 
public:
    Board(int player);
    ~Board();
    // returns the current block on the board
    Block * getNextBlock();
    // returns the next block on the board
    Block * getCurrBlock();
    // sets the first block of the board using the level
    void setFirstBlock(string t);
    // creates the next block based on the level of the player
    void createBlock(string t);
    // sets the next block to the current block on the board
    bool setNewBlock();
    // returns the cell at the given (i, j)
    Cell* getCell(int i, int j);
    // sets the level to the given level
    void setLevel(int l);
    // checks if any of the rows are full and removes them
    void clearBoard();
    // returs the level of the player
    int getLevel();
    // returns the score of the player
    int getScore();
    // returns the player number
    int getPlayer();
    // prints the board
    void print();

};

#endif

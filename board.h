#ifndef _BOARD_H
#define _BOARD_H
#include <vector>
#include <string>
#include "cell.h"
#include "level.h"
using namespace std;

class Block;

class Board{
private:
    std::vector< std::vector < Cell * > > cells;
    Level *level;
    std::vector< Block * > blocks;
    int player;
    int levelnum;
    Block* nextBlock;
    int score;
    // clears the row i and drops all the above blocks down a row
    void clearLines(int i); 
    // prints the board
    void print();

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
    int clearBoard();
    // returs the level of the player
    int getLevel();
    // returns the score of the player
    int getScore();
    // returns the player number
    int getPlayer();
    void detach(Block* b);
    void updateScore(int lines);
};

#endif

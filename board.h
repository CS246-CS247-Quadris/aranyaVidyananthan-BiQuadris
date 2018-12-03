#ifndef _BOARD_H
#define _BOARD_H
#include <vector>
#include <string>
#include "cell.h"
#include "level.h"
#include "window.h"


using namespace std;

class Block;
class Xwindow;

class Board{
private:
    std::vector< std::vector < Cell * > > cells;
    Level *level;
    std::vector< Block * > blocks;
    int player;
    bool blind;
    int X;
    int Y;
    int levelnum;
    Block* nextBlock;
    int score;
    Xwindow *xw;
    // clears the row i and drops all the above blocks down a row
    void clearLines(int i); 
    // prints the board
    void print();

public:
    Board(int player, int X, int Y, int levelnumber );
    ~Board();
    // returns the current block on the board
    Block * getNextBlock();
    // returns the next block on the board
    Block * getCurrBlock();
    // sets the first block of the board using the level
    void init(string t, Xwindow *xw);
    // clears the board and starts a new game
    void restart( int playernum, int a, int b, int levelnumber );
    // creates the next block based on the level of the player
    void createBlock( string t );
    // sets the next block to the current block on the board
    bool setNewBlock();
    // forces the current block to a different type
    bool changeCurrBlock(string t);
    // returns the cell at the given (i, j)
    Cell* getCell(int i, int j);
    // sets the level to the given level
    void setLevel(int l);
    // checks if any of the rows are full and removes them
    int clearBoard();
    // returs the level of the player
    Xwindow *getDisplay();
    int getLevel();
    // returns the score of the player
    int getScore();
    // returns the player number
    int getPlayer();
    // returns the xcoordinate for the top left cell of the board
    int getX();
    //returns the y coordinate for the top left cell of the board
    int getY();
    // sets the blind field
    void setBlind( bool b );
    // returns the blind field
    bool getBlind();
    void setCurrBlock(string type);
    void updateScore(int lines);
    void addScorefromBlock(int l);
};

#endif

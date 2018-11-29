#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstdlib>
#include "cell.h"
#include "block.h"
#include "level.h"
#include "board.h"
#include "biquadris.h"

using namespace std;

int main () {

    string s;
    Biquadris * b = new Biquadris();
    b->getCurrPlayer()->createBlock();
    // the interpreter starts here
    while(cin >> s) {
        if(s == "left"){
        //move the current block one cell to the left
            b->getCurrPlayer()->getCurrBlock()->move( 4 );                 
        }else if(s == "right"){
        //move the current block one cell to the right
            b->getCurrPlayer()->getCurrBlock()->move( 2 );
        }else if(s == "down"){
        //move the current block one cell downward
             b->getCurrPlayer()->getCurrBlock()->move( 3 );
        }else if(s == "clockwise"){
        //rotate the current block 90 degrees clockwise
            b->getCurrPlayer()->getCurrBlock()->rotate( 1 );
        }else if(s == "counterclockwise"){
        //rotate the current block 90 degrees counterclockwise
            b->getCurrPlayer()->getCurrBlock()->rotate( -1 );
        }else if(s == "drop"){
        //drops the current block
            bool drop = true;
            while( drop ) {
                drop = b->getCurrPlayer()->getCurrBlock()->move( 3 );
            } // currplayer's turn is over
            drop = b->getCurrPlayer()->setNewBlock(); // next block becomes curr
            if (!drop) { /* game over */ break; }
            b->switchPlayer();
            b->getCurrPlayer()->createBlock();
        }else if(s == "levelup"){
        //increase the difficulty level of the game by one.
            if(b->getCurrPlayer()->getLevel()< 4 && b->getCurrPlayer()->getLevel()!= -1){
                b->getCurrPlayer()->setLevel(b->getCurrPlayer()->getLevel()+1);
            }
        }else if(s == "leveldown"){
        // decreases the difficulty level of the game by one
            if(b->getCurrPlayer()->getLevel()> 0){
                b->getCurrPlayer()->setLevel(b->getCurrPlayer()->getLevel()-1);
            }
        }else if(s == "norandom"){
        //taking input from the sequence file

        }else if(s == "random"){
        //restore back to randomness

        }else if(s == "sequence"){
        //opens the file whose name is the next string
        //generate blocks according to it

        }else if(s == "restart"){
        //clears the board

        }else if(s == "I"){

        }else if(s == "J"){

        }else if(s == "S"){

        }else if(s == "Z"){

        }else if(s == "I"){

        }else if(s == "T"){

        }else if(s == "O"){

        }
    }
}

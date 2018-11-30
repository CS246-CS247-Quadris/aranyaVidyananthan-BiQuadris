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


void setList(vector<string> &list, int & length, string filename){

   string t;
   ifstream f(filename);
   while(f >> t){
      list.emplace_back(t);
   }
   length = list.size();
}

void aNewLevelZeroBlock(Biquadris* b, vector<string>& list, int & loc, int & length){
   if(loc == length) loc = 0;
   b->getCurrPlayer()->createBlock(list.at(loc));
   loc ++;
}

int main () {
    
    string filenameOne = "sequence1.txt";
    string filenameTwo = "sequence2.txt";
    vector<string> listOne;
    int listLengthOne = 0;
    vector<string> listTwo;
    int listLengthTwo = 0;
    setList(listOne, listLengthOne, filenameOne);
    setList(listTwo, listLengthTwo, filenameTwo);
    int locOne = 0;
    int locTwo = 0;
   // the above code initialize the two vectors of blocknames to read from
    
    string s;
    Biquadris * b = new Biquadris();
    b->setFirstBlocks(listOne.at(locOne), listTwo.at(locTwo));
    locOne ++;
    locTwo ++;
    if(b->playerNum()==1){
       aNewLevelZeroBlock(b, listOne, locOne, listLengthOne);
    }else{
       aNewLevelZeroBlock(b, listTwo, locTwo, listLengthTwo);
    }
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
            if (!drop) { break; } // game over
            b->switchPlayer();
            if(b->getCurrPlayer()->getLevel()== 0){
                if(b->playerNum()==1){
                    aNewLevelZeroBlock(b, listOne, locOne, listLengthOne);
                }else{
                    aNewLevelZeroBlock(b, listTwo, locTwo, listLengthTwo);
                }
            }else if(b->getCurrPlayer()->getLevel()== 1){
                b->getCurrPlayer()->createBlock("n");
            }else if(b->getCurrPlayer()->getLevel()== 2){
                b->getCurrPlayer()->createBlock("n");
            }else if(b->getCurrPlayer()->getLevel()== 3){
                b->getCurrPlayer()->createBlock("n");
            }else{ 
                b->getCurrPlayer()->createBlock("n");
            }
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
    std::cout << "GAME OVER!" << std::endl; 
    delete b;
    listOne.clear();
    listTwo.clear();
}

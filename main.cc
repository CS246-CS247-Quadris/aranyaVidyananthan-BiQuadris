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
#include "window.h"
#include "levelzero.h"

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


bool end(Biquadris * b, bool & heavy) {
    int lines = b->getCurrPlayer()->clearBoard(); // checks if any lines can be cleared
    if(lines > 0) { //updates score if lines are cleared
        b->getCurrPlayer()->updateScore(lines);
        b->newHigh();
    }
    bool dropdown = b->getCurrPlayer()->setNewBlock();
    if(!dropdown) return false; // game over, other player won
    if(b->getCurrPlayer()->getBlind() == true) { // players board returns to normal if it was blind in this turn
        b->getCurrPlayer()->setBlind(false);
    }
    if (heavy == true) heavy = false;
    b->switchPlayer(); // switches the player
    if (lines >= 2) { // if more then 2 lines were cleaed, player gets to choose a special action
        std::cout << "Congratulations! Choose a special action" << std::endl;
        string a;
        cin >> a;
        if (a == "blind") { // blinds the opponents board
            b->getCurrPlayer()->setBlind(true);
        }
        else if (a == "force") { // forces the opponents current block to be one chosen
            string chosenBlockType;
            cin >> chosenBlockType;
            bool check = true;
            check = b->getCurrPlayer()->changeCurrBlock(chosenBlockType);
            if (!check) {return false;} // other player won
        }
        else  //heavy
            heavy = true;
    }
    return true;
}


int main (int argc, char* argv[]) {
    string scriptfile1 = "-scriptfile1";
    string scriptfile2 = "-scriptfile2";
    string seed = "-seed";
    string startlevel = "-startlevel";
    string text = "-text";

    string filenameOne = "sequence1.txt";
    string filenameTwo = "sequence2.txt";
    int seedNumber = 0;
    int levelnumber = 0;
    bool graphics = true;
    bool random = true;
    //commandline interface
    for(int i = 1; i < argc; i++){
        stringstream ss(argv[i]);
        string s = ss.str();
        if (s == scriptfile1) {
            i++;
            stringstream ssfn1(argv[i]);
            filenameOne = ssfn1.str();
           
        }
        else if (s == scriptfile2) { 
            i++;
            stringstream ssfn2(argv[i]);
            filenameTwo = ssfn2.str();
        } 
        else if (s == seed) {
            i++;
            stringstream sn(argv[i]);
            sn >> seedNumber;
        }
        else if (s == startlevel) {
            i++;
            stringstream sl(argv[i]);
            sl >> levelnumber;
        }   
        else if (s == text) {
            graphics = false;
        }
    }
            
    vector<string> listOne;
    int listLengthOne = 0;
    vector<string> listTwo;
    int listLengthTwo = 0;
    setList(listOne, listLengthOne, filenameOne);
    setList(listTwo, listLengthTwo, filenameTwo);
    int locOne = 0;
    int locTwo = 0;
    vector<string> alternate; // the sequence we use under "sequence"
  
    int alternateindex = 0;
 
    int alternatelength = 0;
   // the above code initialize the two vectors of blocknames to read from
    

    string s;
    Biquadris *b = new Biquadris(levelnumber, graphics); 
    if (levelnumber == 0) b->setFirstBlocks(listOne.at(locOne), listTwo.at(locTwo));
    else {b->setFirstBlocks( " ", " " );}
    locOne ++;
    locTwo ++;
    if(b->getCurrPlayer()->getPlayer() == 1){
       aNewLevelZeroBlock(b, listOne, locOne, listLengthOne);
       cout << "current player: " << b->getCurrPlayer()->getPlayer() << endl;
    }else{
       aNewLevelZeroBlock(b, listTwo, locTwo, listLengthTwo);
       cout << "current player "<< b->getCurrPlayer()->getPlayer() << endl;
    }
    b->print();

    bool heavy = false;

    string left = "lef";
    string right = "ri";
    string down = "do";
    string clockwise = "cl";
    string counterclockwise = "co";
    string drop = "dr";
    string levelup = "levelu";
    string leveldown = "leveld";
    string norandom = "norandom";
    string randomness = "random";
    string sequence = "sequence";
    string restart = "re";

    // the interpreter starts here
    while(cin >> s) {
        //move the current block one cell to the left
        if(s.compare(0, 3, left) == 0){
            b->getCurrPlayer()->getCurrBlock()->move(4);
            if(b->getCurrPlayer()->getLevel() == 3 || 
            b->getCurrPlayer()->getLevel()== 4){ 
                b->getCurrPlayer()->getCurrBlock()->move(3);}            
            if (heavy) {
                bool fail = true;
                for (int i = 0; i < 2; ++i) {
                    if (fail == false) break;
                    fail = b->getCurrPlayer()->getCurrBlock()->move(3);
                }
                if (fail == false) {
                    bool gameover = end(b, heavy);
                    if (!gameover) break;
                    // generates next block for the new player based on level of player
                    if(b->getCurrPlayer()->getLevel() == 0) {
                        if(b->getCurrPlayer()->getPlayer() == 1) aNewLevelZeroBlock(b, listOne, locOne, listLengthOne);
                   else {aNewLevelZeroBlock(b, listTwo, locTwo, listLengthTwo);}
                    }
                    else if(b->getCurrPlayer()->getLevel() == 1) b->getCurrPlayer()->createBlock("n");
                    else if(b->getCurrPlayer()->getLevel() == 2) b->getCurrPlayer()->createBlock("n");
                    else if(b->getCurrPlayer()->getLevel() == 3) b->getCurrPlayer()->createBlock("n");
                    else {b->getCurrPlayer()->createBlock("n");}
                }
            }    
        }

        //move the current block one cell to the right
        else if(s.compare(0, 2, right) == 0){
            b->getCurrPlayer()->getCurrBlock()->move(2);
            if(b->getCurrPlayer()->getLevel() == 3 ||
            b->getCurrPlayer()->getLevel() == 4) { 
                b->getCurrPlayer()->getCurrBlock()->move(3);}
            if (heavy) {
                bool fail = true;
                for (int i = 0; i < 2; ++i) {
                    if (fail == false) {break;}
                    fail = b->getCurrPlayer()->getCurrBlock()->move(3);
                }
                if (fail == false) {
                    bool gameover = end(b, heavy);
                    if (!gameover) {break;}
                    // generates next block for the new player based on level of player
                    if(b->getCurrPlayer()->getLevel() == 0) {
                        if(b->getCurrPlayer()->getPlayer() == 1) {aNewLevelZeroBlock(b, listOne, locOne, listLengthOne);}
                        else {aNewLevelZeroBlock( b, listTwo, locTwo, listLengthTwo);}
                    }
                    else if(b->getCurrPlayer()->getLevel() == 1) b->getCurrPlayer()->createBlock("n");
                    else if(b->getCurrPlayer()->getLevel() == 2) b->getCurrPlayer()->createBlock("n");
                    else if(b->getCurrPlayer()->getLevel() == 3) b->getCurrPlayer()->createBlock("n");
                    else {b->getCurrPlayer()->createBlock("n");}
                }
            }
        }

        //move the current block one cell downward
        else if(s.compare (0, 2, down) == 0){
            b->getCurrPlayer()->getCurrBlock()->move(3);
            if(b->getCurrPlayer()->getLevel() == 3 ||
            b->getCurrPlayer()->getLevel()== 4){ 
                b->getCurrPlayer()->getCurrBlock()->move(3);}
        }
 
        //rotate the current block 90 degrees clockwise  
        else if(s.compare (0, 2, clockwise) == 0){
            b->getCurrPlayer()->getCurrBlock()->rotate(1);
            if(b->getCurrPlayer()->getLevel() == 3 ||
               b->getCurrPlayer()->getLevel() == 4) { 
               b->getCurrPlayer()->getCurrBlock()->move(3);}
        }

        //rotate the current block 90 degrees counterclockwise
        else if(s.compare(0, 2, counterclockwise) == 0){
            b->getCurrPlayer()->getCurrBlock()->rotate(-1);
            if(b->getCurrPlayer()->getLevel() == 3 ||
               b->getCurrPlayer()->getLevel() == 4) { 
               b->getCurrPlayer()->getCurrBlock()->move(3);}
        }

        //drops the current block
        else if(s.compare(0, 2, drop) == 0){
            bool dropdown = true;
            while(dropdown) {
                dropdown = b->getCurrPlayer()->getCurrBlock()->move(3);
            }  // currplayer's turn is over

            bool gameover = end(b, heavy);
            if (!gameover) {break;}
            // generates next block for the new player based on level of player
            if(b->getCurrPlayer()->getLevel() == 0) {
                if(b->getCurrPlayer()->getPlayer() == 1) aNewLevelZeroBlock(b, listOne, locOne, listLengthOne);
                else {aNewLevelZeroBlock(b, listTwo, locTwo, listLengthTwo);}
            }
            else if(b->getCurrPlayer()->getLevel() == 1) b->getCurrPlayer()->createBlock("n");
            else if(b->getCurrPlayer()->getLevel() == 2) b->getCurrPlayer()->createBlock("n");
           else { 
                if(random)
                    b->getCurrPlayer()->createBlock( "n" );
                else
                    aNewLevelZeroBlock(b, alternate,alternateindex, alternatelength);
            }
        }

        //increase the difficulty level of the game by one
        else if(s.compare(0, 6, levelup ) == 0){
            if(b->getCurrPlayer()->getLevel()< 4 && b->getCurrPlayer()->getLevel()!= -1)
                b->getCurrPlayer()->setLevel(b->getCurrPlayer()->getLevel()+1);
        }

        // decreases the difficulty level of the game by one
        else if(s.compare(0, 6, leveldown) == 0){
            if(b->getCurrPlayer()->getLevel()> 0)
                b->getCurrPlayer()->setLevel(b->getCurrPlayer()->getLevel()-1);
        }

        //taking input from the sequence file
        else if(s == norandom){
            random = false;
            string fn;
            cin >> fn;
            setList(alternate, alternatelength, fn);
        }

        //restore back to randomness
        else if(s == randomness){
            random = true;
        }

        // clears the board
        else if(s.compare(0, 2, restart) == 0){
            b->restart(levelnumber, graphics);
            if (levelnumber == 0) {b->setFirstBlocks(listOne.at(locOne), listTwo.at(locTwo)); }
            else {b->setFirstBlocks( " ", " ");}
            // generates next block for the new player based on level of player
            if(b->getCurrPlayer()->getLevel() == 0) {
               if(b->getCurrPlayer()->getPlayer() == 1) {aNewLevelZeroBlock( b, listOne, locOne, listLengthOne);}
               else {aNewLevelZeroBlock(b, listTwo, locTwo, listLengthTwo);}
            }
            else if(b->getCurrPlayer()->getLevel() == 1) b->getCurrPlayer()->createBlock("n");
            else if(b->getCurrPlayer()->getLevel() == 2) b->getCurrPlayer()->createBlock("n");
            else if(b->getCurrPlayer()->getLevel() == 3) b->getCurrPlayer()->createBlock("n");
            else {b->getCurrPlayer()->createBlock("n");}
 
        }

        // changes the corrent block to type I
        else if(s == "I") {
            bool force = b->getCurrPlayer()->changeCurrBlock("I");
            if (!force) break; // other player won

        // changes the corrent block to type J
        }else if(s == "J") {
            bool force = b->getCurrPlayer()->changeCurrBlock("J");
            if (!force) break; // other player won

        // changes the corrent block to type S
        }else if(s == "S") {
            bool force = b->getCurrPlayer()->changeCurrBlock("S");
            if (!force) break; // other player won

        // changes the corrent block to type Z
        }else if(s == "Z") {
            bool force = b->getCurrPlayer()->changeCurrBlock("Z");
            if (!force) break; // other player won

        // changes the corrent block to type L
        }else if(s == "L") {
            bool force = b->getCurrPlayer()->changeCurrBlock("L");
            if (!force) break; // other player won

        // changes the corrent block to type T
        }else if(s == "T") {
            bool force = b->getCurrPlayer()->changeCurrBlock("T");
            if (!force) break; // other player won

        // changes the corrent block to type O
        }else if(s == "O") {
            bool force = b->getCurrPlayer()->changeCurrBlock("O");
            if (!force) break; // other player won
        }

    b->print();
    }

    std::cout << "GAME OVER!" << std::endl; 
    if (b->getCurrPlayer()->getPlayer() == 1) std::cout << "Player 2 won!" << std::endl;
    else {std::cout << "Player 1 won!" << std::endl;}
    delete b;
    listOne.clear();
    listTwo.clear();
}

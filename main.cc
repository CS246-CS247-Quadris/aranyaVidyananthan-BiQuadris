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


void setList( vector<string> &list, int & length, string filename ){

   string t;
   ifstream f( filename );
   while( f >> t ){
      list.emplace_back(t);
   }
   length = list.size();
}

void aNewLevelZeroBlock(Biquadris* b, vector<string>& list, int & loc, int & length){
   if( loc == length ){ loc = 0;}
   b->getCurrPlayer()->createBlock( list.at(loc) );
   loc ++;
}

int main (int argc, char* argv[]) {
    
    string filenameOne = "sequence1.txt";
    string filenameTwo = "sequence2.txt";
    int seedNumber = 0;
    int levelnumber = 0;
    int argsNum = argc -1;

    //commandline interface
    for(int i = 0; i < argsNum; i++){
        stringstream ss(argv[i]);
        string s = ss.str();
        if( s == "-scriptfile1" ) {
            i++;
            stringstream ssfn1(argv[i]);
            filenameOne = ssfn1.str();
           
        }
        else if( s == "-scriptfile2" ) { 
            i++;
            stringstream ssfn2(argv[i]);
            filenameTwo = ssfn2.str();
        } 
        else if( s == "-seed" ) {
            i++;
            stringstream sn(argv[i]);
            sn >> seedNumber;
        }
        else if( s == "-startlevel" ) {
            i++;
            stringstream sl(argv[i]);
            sl >> levelnumber;
        }   
    }
            
    vector<string> listOne;
    int listLengthOne = 0;
    vector<string> listTwo;
    int listLengthTwo = 0;
    setList( listOne, listLengthOne, filenameOne );
    setList( listTwo, listLengthTwo, filenameTwo );
    int locOne = 0;
    int locTwo = 0;
   // the above code initialize the two vectors of blocknames to read from
    



    string s;
    Biquadris *b = new Biquadris( levelnumber ); 
    b->setFirstBlocks( listOne.at(locOne), listTwo.at(locTwo) );
    locOne ++;
    locTwo ++;
    if( b->getCurrPlayer()->getPlayer() == 1 ){
       aNewLevelZeroBlock(b, listOne, locOne, listLengthOne);
       cout << "current player: " << b->getCurrPlayer()->getPlayer() << endl;
    }else{
       aNewLevelZeroBlock(b, listTwo, locTwo, listLengthTwo);
       cout << "current player "<< b->getCurrPlayer()->getPlayer() << endl;
    }
    b->print();
    // the interpreter starts here
    while( cin >> s ) {
        if( s.compare( 0, 3, "lef" ) == 0 ){
        //move the current block one cell to the left
            b->getCurrPlayer()->getCurrBlock()->move( 4 );
            if( b->getCurrPlayer()->getLevel() == ( 3||4 ) ){
                b->getCurrPlayer()->getCurrBlock()->move( 3 );
            }                
        }else if( s.compare( 0, 2, "ri") == 0 ){
        //move the current block one cell to the right
            b->getCurrPlayer()->getCurrBlock()->move( 2 );
            if( b->getCurrPlayer()->getLevel() == ( 3||4 ) ) {
                b->getCurrPlayer()->getCurrBlock()->move( 3 );
            }
        }else if( s.compare ( 0, 2, "do" ) == 0 ){
        //move the current block one cell downward
            b->getCurrPlayer()->getCurrBlock()->move( 3 );
            if( b->getCurrPlayer()->getLevel() == ( 3||4 ) ){
                b->getCurrPlayer()->getCurrBlock()->move( 3 );
            }
        }else if( s.compare ( 0, 2, "cl" ) == 0 ){
        //rotate the current block 90 degrees clockwise
            b->getCurrPlayer()->getCurrBlock()->rotate( 1 );
            if( b->getCurrPlayer()->getLevel() == ( 3||4 ) ) {
                b->getCurrPlayer()->getCurrBlock()->move( 3 );
            }
        }else if( s.compare( 0, 2,"co" ) == 0 ){
        //rotate the current block 90 degrees counterclockwise
            b->getCurrPlayer()->getCurrBlock()->rotate( -1 );
            if( b->getCurrPlayer()->getLevel() == ( 3||4 ) ) {
                b->getCurrPlayer()->getCurrBlock()->move( 3 );
            }
        }else if( s.compare( 0, 2, "dr")  == 0 ){
        //drops the current block
            bool drop = true;
            while( drop ) {
                drop = b->getCurrPlayer()->getCurrBlock()->move( 3 );
            }  // currplayer's turn is over
            // next block becomes curr
            int lines = b->getCurrPlayer()->clearBoard();
            if( lines > 0 ) { 
                b->getCurrPlayer()->updateScore( lines );
                b->newHigh();
            }
            drop = b->getCurrPlayer()->setNewBlock();
            if( !drop ) { break; } // game over // other player won
            if( b->getCurrPlayer()->getBlind() == true ) { // players board returns to normal
                b->getCurrPlayer()->setBlind( false );
            } 
            b->switchPlayer();
            if ( lines >= 2 ) {
                string a;
                cin >> a;
                if ( a == "blind" ) {
                    b->getCurrPlayer()->setBlind( true );
                }
                else if ( a == "force" ) {
                    string chosenBlockType;
                    cin >> chosenBlockType;
                    bool force = b->getCurrPlayer()->changeCurrBlock( chosenBlockType );
                    if ( !force ) { break; } // other player won
                }
                else { //heavy

                }
            }
            if( b->getCurrPlayer()->getLevel() == 0 ){
                if( b->getCurrPlayer()->getPlayer() == 1 ){
                    aNewLevelZeroBlock(b, listOne, locOne, listLengthOne);
               }else{
                    aNewLevelZeroBlock(b, listTwo, locTwo, listLengthTwo);
               }
            //}else if(b->getCurrPlayer()->getLevel()== 1){
               // b->getCurrPlayer()->createBlock("n");
            //}else if(b->getCurrPlayer()->getLevel()== 2){
               // b->getCurrPlayer()->createBlock("n");
            //}else if(b->getCurrPlayer()->getLevel()== 3){
               // b->getCurrPlayer()->createBlock("n");
            }
            else{ 
                b->getCurrPlayer()->createBlock( "n" );
            }
        }else if( s.compare(0, 6, "levelu") == 0 ){
        //increase the difficulty level of the game by one.
            if(b->getCurrPlayer()->getLevel()< 4 && b->getCurrPlayer()->getLevel()!= -1){
                b->getCurrPlayer()->setLevel(b->getCurrPlayer()->getLevel()+1);
            }
        }else if( s.compare(0, 6, "leveld") == 0 ){
        // decreases the difficulty level of the game by one
            if(b->getCurrPlayer()->getLevel()> 0){
                b->getCurrPlayer()->setLevel(b->getCurrPlayer()->getLevel()-1);
            }
        }else if( s == "norandom" ){
        //taking input from the sequence file

        }else if( s == "random" ){
        //restore back to randomness

        }else if( s == "sequence" ){
        //opens the file whose name is the next string
        //generate blocks according to it

        }else if( s.compare( 0,2,"re" ) == 0 ){
        //clears the board

        }else if( s == "I" ) {
           // b->getCurrPlayer()->Block( "I" );
            //b->getCurrPlayer()->setNewBlock();
            bool force = b->getCurrPlayer()->changeCurrBlock( "I" );
            if ( !force ) { break; } // other player won
        }else if( s == "J" ) {
            bool force = b->getCurrPlayer()->changeCurrBlock( "J" );
            if ( !force ) { break; } // other player won
        }else if( s == "S" ) {
            bool force = b->getCurrPlayer()->changeCurrBlock( "S" );
            if ( !force ) { break; } // other player won
        }else if( s == "Z" ) {
            bool force = b->getCurrPlayer()->changeCurrBlock( "Z" );
            if ( !force ) { break; } // other player won
        }else if( s == "L" ) {
            bool force = b->getCurrPlayer()->changeCurrBlock( "L" );
            if ( !force ) { break; } // other player won
        }else if( s == "T" ) {
            bool force = b->getCurrPlayer()->changeCurrBlock( "T" );
            if ( !force ) { break; } // other player won
        }else if( s == "O" ) {
            bool force = b->getCurrPlayer()->changeCurrBlock( "O" );
            if ( !force ) { break; } // other player won
        }
    b->print();
    }
    std::cout << "GAME OVER!" << std::endl; 
    if ( b->getCurrPlayer()->getPlayer() == 1 ) { std::cout << "Player 2 won!" << std::endl;}
    else { std::cout << "Player 1 won!" << std::endl; }
    delete b;
    listOne.clear();
    listTwo.clear();
}

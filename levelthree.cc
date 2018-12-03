#include <cstdlib>
#include<string>
#include "levelthree.h"
#include "oblock.h"
#include "iblock.h"
#include "sblock.h"
#include "jblock.h"
#include "lblock.h"
#include "tblock.h"
#include "zblock.h"

using namespace std;
class Board;

//constructor
LevelThree::LevelThree(): Level{3}{}


//destructor
LevelThree::~LevelThree(){

}

//get the Level number

const int LevelThree::getLevel(){

   return levelNumber;
}

//using random number to control the probability of
//which type of new block is generated
Block* LevelThree::nextBlock(Board* b, string t){
   if(t == "n"){
       int rn = rand()%9; // rn in the range 0 to 8
       if(rn == 0 || rn == 7){
          Block* bl = new SBlock(3,b);
          return bl;
       }else if(rn == 1 || rn == 8){
          Block *bl = new ZBlock(3,b);
          return bl;
       }else if(rn == 2){
          Block *bl = new TBlock(3,b);
          return bl;
       }else if(rn == 3){
          Block *bl = new IBlock(3,b);
          return bl;
       }else if(rn == 4){
          Block *bl = new JBlock(3,b);
          return bl;
       }else if(rn == 5){
          Block *bl = new LBlock(3,b);
          return bl;
       }else{
          Block *bl = new OBlock(3,b);
          return bl;
       }
   }else if(t == "S"){
       return new SBlock(3,b);
   }else if(t == "T"){
       return new TBlock(3,b);
   }else if(t == "Z"){
       return new ZBlock(3,b);
   }else if(t == "O"){
       return new OBlock(3,b);
   }else if(t == "J"){
       return new JBlock(3,b);
   }else if(t == "L"){
       return new LBlock(3,b);
   }else{
       return new IBlock(3,b);
   }
   
}



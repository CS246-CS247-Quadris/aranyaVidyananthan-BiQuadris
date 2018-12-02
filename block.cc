#include "block.h"
#include "cell.h"
#include "board.h"
#include "window.h"

Block::Block(int levelcreated, char type, Board * g ):shape{}, 
    temp{}, levelcreated{levelcreated},type{type}, orientation{1}, g{g}, removed{0}, scale{17}{}


Block::~Block() {}


void Block::clearLine(int rowNum){
    int index = shape.size();
    if(shape.empty()){return;}
    char c = shape[0]->getType();
    for(int i = 0; i < index; i ++){
        g->getDisplay()->fillRectangle( (shape[index]->getX() + g->getX())*scale, (shape[index]->getY() + g->getY())*scale, scale, scale, 0 );
        if(shape[i]->getY() > rowNum){
            temp.emplace_back(g->getCell(shape[i]->getX(),shape[i]->getY()));
            //in this case, it is just the same cell originally in shape
        }else if(shape[i]->getY() == rowNum){
            shape[i]->setStatus(true);
            shape[i]->setType(' ');
            removed ++;
        }else{
            shape[i]->setType(' ');
            shape[i]->setStatus(true);
            int x = shape[i]->getX();
            int y = shape[i]->getY()+1;
            temp.emplace_back(g->getCell(x , y));
        }
    }
    int newsize = temp.size();
    shape.clear();
    for(int i=0; i < newsize; i ++){
        shape.emplace_back(temp[i]);
        shape.back()->setType(c);
        shape.back()->setStatus(false);
        // draws the block based on the type of the block
        if ( c == 'I' ) {
            g->getDisplay()->fillRectangle( (shape.back()->getX() + g->getX())*scale, (shape.back()->getY() + g->getY())*scale, scale, scale, 2 );
        }
        else if ( c == 'J' ) {
            g->getDisplay()->fillRectangle( (shape.back()->getX() + g->getX())*scale, (shape.back()->getY() + g->getY())*scale, scale, scale, 3 );
        }
        else if ( c == 'L' ) {
            g->getDisplay()->fillRectangle( (shape.back()->getX() + g->getX())*scale, (shape.back()->getY() + g->getY())*scale, scale, scale, 4 );
        }
        else if ( c == 'S' ) {
            g->getDisplay()->fillRectangle( (shape.back()->getX() + g->getX())*scale, (shape.back()->getY() + g->getY())*scale, scale, scale, 5 );
        }
        else if ( c == 'T' ) {
            g->getDisplay()->fillRectangle( (shape.back()->getX() + g->getX())*scale, (shape.back()->getY() + g->getY())*scale, scale, scale, 6 );
        }
        else if ( c == 'O' ) {
            g->getDisplay()->fillRectangle( (shape.back()->getX() + g->getX())*scale, (shape.back()->getY() + g->getY())*scale, scale, scale, 7 );
        }
        else {
            g->getDisplay()->fillRectangle( (shape.back()->getX() + g->getX())*scale, (shape.back()->getY() + g->getY())*scale, scale, scale, 8 );
        }
    }
    temp.clear();
    if(shape.size()==0){g->addScorefromBlock(levelcreated);}
}



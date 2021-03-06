#include "block.h"
#include "cell.h"
#include "board.h"
#include "window.h"

Block::Block(int levelcreated, char type, Board * g):shape{}, 
    temp{}, levelcreated{levelcreated}, type{type}, orientation{1}, g{g}, removed{0}, scale{17}{}


Block::~Block() {}


void Block::clearBlock() {
    int i = shape.size();
    for (int n = 0; n < i; ++n) {
        shape[n]->setType(' ');
        shape[n]->setStatus(true);
        if (g->getDisplay()) 
            g->getDisplay()->fillRectangle((shape[n]->getX()+ g->getX())*scale, (shape[n]->getY() + g->getY())*scale, scale, scale, 0);
    }
}

// clears the row passed, and moves any blocks above the line cleared
void Block::clearLine(int rowNum){
    
    if(shape.empty()){return;}
    int index = shape.size();
    char c = shape[0]->getType();
    for(int i = 0; i < index; i ++){
        if(shape[i]->getY() > rowNum){
            temp.emplace_back(g->getCell(shape[i]->getX(),shape[i]->getY()));
            //in this case, it is just the same cell originally in shape
        }
        else if(shape[i]->getY() == rowNum){
            shape[i]->setStatus(true);
            shape[i]->setType(' ');
            if (g->getDisplay()) 
                g->getDisplay()->fillRectangle((shape[i]->getX()+ g->getX())*scale, (shape[i]->getY() + g->getY())*scale, scale, scale, 0);
            removed ++;
        } 
        else{
            shape[i]->setType(' ');
            shape[i]->setStatus(true);
            int x = shape[i]->getX();
            int y = shape[i]->getY()+1;
            temp.emplace_back(g->getCell(x, y));
            if (g->getDisplay())
                g->getDisplay()->fillRectangle((x + g->getX())*scale, (shape[i]->getY() + g->getY())*scale, scale, scale, 0);
        }
    }
    int newsize = temp.size();
    shape.clear();
    for(int i = 0; i < newsize; i ++ ){
        shape.emplace_back(temp[i]);
        shape.back()->setType(c);
        shape.back()->setStatus(false);
        // draws the block based on the type of the block
        if (g->getDisplay()) {
            if (c == 'I') 
                g->getDisplay()->fillRectangle((shape.back()->getX() + g->getX())*scale, (shape.back()->getY() + g->getY())*scale, scale, scale, 2);
            else if (c == 'J') 
                g->getDisplay()->fillRectangle((shape.back()->getX() + g->getX())*scale, (shape.back()->getY() + g->getY())*scale, scale, scale, 3);
            else if (c == 'L') 
                g->getDisplay()->fillRectangle((shape.back()->getX() + g->getX())*scale, (shape.back()->getY() + g->getY())*scale, scale, scale, 4);
            else if (c == 'S') 
                g->getDisplay()->fillRectangle((shape.back()->getX() + g->getX())*scale, (shape.back()->getY() + g->getY())*scale, scale, scale, 5);          
            else if (c == 'T') 
                g->getDisplay()->fillRectangle((shape.back()->getX() + g->getX())*scale, (shape.back()->getY() + g->getY())*scale, scale, scale, 6);
            else if (c == 'O') 
                g->getDisplay()->fillRectangle((shape.back()->getX() + g->getX())*scale, (shape.back()->getY() + g->getY())*scale, scale, scale, 7);
            else 
                g->getDisplay()->fillRectangle((shape.back()->getX() + g->getX())*scale, (shape.back()->getY() + g->getY())*scale, scale, scale, 8);
        }
    }
    temp.clear();
    if(shape.empty()){g->addScorefromBlock(levelcreated);}
}


int Block::getRemoved() {
    return removed;
}





#include "block.h"
#include "cell.h"
#include "board.h"


Block::Block( char type, Board * g ):shape{}, 
    temp{}, type{type}, orientation{1}, g{g}, removed{0}{}

Block::~Block() {}

void Block::clearLine(int rowNum){
    int index = shape.size();
    if(shape.empty()){return;}
    char c = shape[0]->getType();
    for(int i = 0; i < index; i ++){
        if(shape[i]->getY() >rowNum){
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
    }
    temp.clear();
 


}

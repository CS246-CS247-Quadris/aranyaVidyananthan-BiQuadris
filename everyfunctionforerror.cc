Board::Board( int player ) {
    level = new LevelZero();
    levelnum = 0;
    player = player;
    cells.resize(11); // 11 columns
    for(int i = 0; i < 11; ++i){
        cells[i].resize(18); // 18 rows
        for(int j = 0; j < 18; ++j){
           cells[i][j] =  new Cell(i,j);// create empty cells
        }
    }
    std::cout << cells[0][3]->getX() << std::endl;
}


void Board::setFirstBlock() {
    Block * b = level->nextBlock( this );
    blocks.emplace_back( b ); // adds the currblock
    b->set();
}

Block* LevelZero::nextBlock( Board * b){
   return new IBlock( b );
}

bool IBlock::set () {
    // check if the four cells needed for block are empty
    if( (g->getCell(0,3))->getStatus() == true ) {
        temp.emplace_back( g->getCell(0,3));
    }
    else { temp.clear(); return false; }
    if( (g->getCell(1,3))->getStatus() == true ) {
        temp.emplace_back( g->getCell(1,3));
    }
    else { temp.clear(); return false; }
    if( (g->getCell(2,3))->getStatus() == true ) {
        temp.emplace_back( g->getCell(2,3) );
    }
    else { temp.clear(); return false; }
    if( (g->getCell(3,3))->getStatus() == true ) {
        temp.emplace_back( g->getCell(3,3));
    }
    else { temp.clear(); return false; }
    for (int index = 0; index < 4; index ++) {
        shape[index] = temp[index];
        shape[index]->setType( 'I' );
        shape[index]->setStatus( false );
    }
    temp.clear();
    return true;
}

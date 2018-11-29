Board::Board( int player ):level{new LevelZero}, blocks{}, player{player},
    levelnum{0}, nextBlock{}, score{0} {
        cells.resize(11); // 11 columns
        for(int i = 0; i < 11; ++i){
            cells[i].resize(18); // 18 rows
            for(int j = 0; j < 18; ++j){
                cells[i][j] =  new Cell(i,j);// create empty cells
            }
        }
}

Cell::Cell( int x, int y ): isempty{true}, t{}, x{x}, y{y}{}


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
    ..............
}

Cell * Board::getCell(int i, int j){
   return cells[i][j];
}


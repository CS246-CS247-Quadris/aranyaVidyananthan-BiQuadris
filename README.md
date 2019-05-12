# CS246

A game of Biquadris consists of two boards, each 11 columns wide and 15 rows high. Blocks
consisting of four cells (tetrominoes) appear at the top of each board, and are dropped
onto their respective boards so as not to leave any gaps. Once an entire row has been filled, it
disappears, and the blocks above move down by one unit.
A player's turn ends when he/she has dropped a block onto the board. During a player's turn, 
the block that the opponent will have to play next is already at the top of the opponent's 
board (and if it doesn't fit, the opponent has lost). The major components of the system are as follows:

Blocks:
There are seven types of blocks, shown below with their names and initial configurations:
I-block J-block L-block O-block S-block Z-block T-block

Blocks can be moved and rotated. When a block is rotated, it should be done such that the
position of the lower left corner of the smallest rectangle containing the block is preserved.
When a block is dropped onto the board, any rows that have been completely
filled as a result of the block having dropped are removed from the board, and the
remaining blocks above these rows move down to fill the gap.

Levels:
1. Level 0: Takes its blocks in sequence from the files sequence1.txt (for player 1) and sequence2.txt 
(for player 2), or from other files, whose names are supplied on the command line. This level is
non-random, and can be used to test with a predetermined set of
blocks. 
2. Level 1: The block selector will randomly choose a block with probabilities skewed such that
S and Z blocks are selected with probability 1/12 each, and the other blocks are selected with
probability 1/6 each.
3. Level 2: All blocks are selected with equal probability.
4. Level 3: The block selector will randomly choose a block with probabilities skewed such that
S and Z blocks are selected with probability 2/9 each, and the other blocks are selected with
probability 1/9 each. Moreover, blocks generated in level 3 are 'heavy', every command to
move or rotate the block will be followed immediately and automatically by a downward move
of one row (if possible).

Special Actions:
If a player, upon dropping a block, clears two or more rows simultaneously, a special action is
triggered. A special action is a negative infuence on the opponent's game. When a special action
is triggered, the game will prompt the player for his/her chosen action. Available actions are as
follows:
1. blind The player's board, from columns 3-9, and from rows 3-12, is covered with question
marks (?), until the player drops a block; then the display reverts to normal.
2. heavy Every time a player moves a block left or right, the block automatically falls by two
rows, after the horizontal move. If it is not possible for the block to drop two rows, it is
considered to be dropped, and the turn ends. If the player is already in a level in which
blocks are heavy, the effect is cumulative (i.e., the player suers from both effects).
3. force Change the opponent's current block to be one of the player's choosing. If the block
cannot be placed in its initial position, the opponent loses. (E.g., force Z)

Commands:
You interact with the system by issuing text-based commands. The following commands are to be
supported:
1. left moves the current block one cell to the left. 
2. right moves the current block one cell to the right. 
3. down moves the current block one cell to the down.
4. clockwise rotates the block 90 degrees clockwise.
5. counterclockwise rotates the block 90 degrees counterclockwise.
6. drop drops the current block. It is (in one step) moved downward as far as possible until
it comes into contact with either the bottom of the board or a block. This command also
triggers the next block to appear. Even if a block is already as far down as it can go (as a
result of executing the down command), it still needs to be dropped in order to get the next
block.
7. levelup Increases the difficulty level of the game by one. The block showing as next still
comes next, but subsequent blocks are generated using the new level. If there is no higher
level, this command has no effect.
8. leveldown Decreases the diffculty level of the game by one. The block showing as next still
comes next, but subsequent blocks are generated using the new level. If there is no lower
level, this command has no effect.
9. norandom file Relevant only during levels 3 and 4, this command makes these levels non-
random, instead taking input from the sequence file, starting from the beginning. This is
to facilitate testing.
10. random Relevant only during levels 3 and 4, this command restores randomness in these levels.
11. I, J, L, etc. Useful during testing, these commands replace the current undropped block with
the stated block. Heaviness is detemined by the level number. Note that, for heavy blocks,
these commands do not cause a downward move.

Scoring:
The game is scored as follows: when a line (or multiple lines) is cleared, you score points equal to
(your current level, plus number of lines) squared. (For example, clearing a line in level 2 is worth 9
points.) In addition, when a block is completely removed from the screen you score points equal to
the level you were in when the block was generated, plus one, squared.

Command-line Interface:
1. -text runs the program in text-only mode. No graphics are displayed. The default behaviour
(no -text) is to show both text and graphics.
2. -scriptfile1 xxx Uses xxx instead of sequence1.txt as a source of blocks for level 0, for
player 1.
3. -scriptfile2 xxx Uses xxx instead of sequence2.txt as a source of blocks for level 0, for
player 2.
4. -startlevel n Starts the game in level n. The game starts in level 0 if this option is not
supplied.

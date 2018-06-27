# Filler

Filler is an algorithmic game which consists in filling a grid of a known size in advance with pieces of random size and shapes, without the pieces being stacked more than one square above each other and without them exceeding the grid. If one of these conditions is not met, the game stops.

Each successfully placed piece yields a number of points, and has only one player, the goal of the game could be to get the best score possible. However, it is with two players that the filler takes all his interest. Each player has for the purpose of placing as many pieces as possible while attempting to prevent his opponent from doing the same. At the end of the game, the one with the most points wins the match.

Compile: ```./filler_vm -p1 user1 -p2 user2 -v -f map```

Allowed functions:
* read
* write
* malloc
* free

# Mandatory part

* In this game, two players fight each other. They play one after the other.
* The goal is to collect as many points as possible by placing the highest number of pieces on the the game board.
* The board is defined by X columns and N lines, it will then become X*N cells.
* At the beginning of each turn, you will receive your game piece.
* A game piece is defined by X columns and N lines, so it will be X*N cells. Inside each game piece, will be included a shape of one or many cells.
* To be able to place a piece on the board, it is mandatory that one, and only one cell of the shape (in your piece) covers the cell of a shape placed previously (your territory).
* The shape must not exceed the dimensions of the board
* When the game starts, the board already contains one shape.
* The game stops at the first error: either when a game piece cannot be placed anymore or it has been wrongly placed.

# How the game works

* At each turn, the filler will send the updated map and a new token to the player concerned.
* The player concerned will write on the standard output his or her piece’s coordinates to place it on the board.
* The filler will send the map and a new piece to the other player.

# Visualisation

Compile: ```./filler_vm -p1 user1 -p2 user2 -v -f map | ./visualization/visual```

Created using MLX library. ESC key works.

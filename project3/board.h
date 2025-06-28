#include <iostream>
#include <fstream>
#include "Pos.h"

struct Ship{
    Pos curr;
    Pos prev;
    int dir;
};

struct Hunter{
    Pos curr;
    Pos prev;
    int dir;
};

//struct for the Board
struct Board{
    int row, col, ztotal;
    char Board[100][100];
    Pos player;
    int pdir;
    bool moving;
    Pos spawn[100];
    Pos playerPrev;
    bool immoral;
    Ship ships[500];
    int shipCount;
    Hunter hunters[500];
    int hunterCount;
};

//function for printBoard
bool printBoard(string filename, Board& b);
bool reachGoal(const Board& b);
bool collision(Board& b);
void moveShip(Board& b);
void moveHunter(Board& b);



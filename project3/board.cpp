#include <fstream>
#include <iostream>
#include <unistd.h>
#include <cmath>
using namespace std;
#include "Pos.h"
#include "board.h"

bool printBoard(string filename, Board& b){
    //read in the file
    ifstream fin(filename);
    if (!fin){
        return false;
    }

    //read in the file contents
    char junk;
    fin >> b.row >> junk >> b.col >> b.ztotal;
    fin.get();

    int zcount = 0;
    //for loop to calculate the row and column
    for(int i = 0; i < b.row; i++){
        for(int j = 0; j < b.col; j++){
            char ch = fin.get();
            //player row and column
            if(ch == 'Y'){
                b.player = Pos{i, j};
                ch = ' ';
            }
            //spawn point row and column
            else if(ch == 'Z' && zcount < 100){
                b.spawn[zcount++] = Pos{i, j};
                ch = ' ';
            }
            b.Board[i][j] = ch;
            
        }
        fin.get();
    }
    b.pdir = 0;
    b.moving = false;
    b.immoral = false;

    //randomize ship spawn points
    srand(getpid());
    b.shipCount = 0;
    b.hunterCount = 0;
    for(int i = 0; i < b.ztotal; i++){
        for(int j = 0; j < 5; j++){
            //space ship spawn point
            b.ships[b.shipCount].curr = b.spawn[i];
            b.ships[b.shipCount].prev = b.spawn[i];
            b.ships[b.shipCount].dir = (rand() % 4) * 90;
            b.shipCount++;
        }
        //hunter spawn point
        b.hunters[b.hunterCount].curr = b.spawn[i];
        b.hunters[b.hunterCount].prev = b.spawn[i];
        b.hunters[b.hunterCount].dir = (rand() % 4);
        b.hunterCount++;
    }
    return true;
}

bool reachGoal(const Board& b){
    for(int i = 0; i < b.row; i++){
        for(int j = 0; j < b.col; j++){
            //if statement for P landing near X
            if(b.Board[i][j] == 'X'){
                if (dist(b.player, Pos{i, j}) <= 1)
                    return true;
            }
        }
    }
    return false;
}

//determine if a collision happened between spaceship and player
bool collision(Board& b){
    for(int i = 0; i < b.shipCount; i++){
        Ship s = b.ships[i];
        if(equal(s.curr, b.player))
            return true;
        if(equal(s.curr, b.playerPrev) && equal(s.prev, b.player))
            return true;
    }
    return false;
}

//enable movement of the space ship across the board, randomly
void moveShip(Board& b){
    for(int i = 0; i < b.shipCount; i++){
        Ship& s = b.ships[i];
        s.prev = s.curr;

        if(rand() % 10 == 0){ //randomize movement
            int angle;
            if(rand() % 2 == 0){
                angle = -90;
            }
            else
                angle = 90;
            s.dir = turn(s.dir, angle);
        }
        Pos next = step(s.curr, s.dir);
        if(b.Board[next.row][next.col] == ' ')
            s.curr = next;
        else{ //bounce function for ships
            int reverse = turn(s.dir, 180);
            Pos back = step(s.curr, reverse);
            if(b.Board[back.row][back.col] == ' '){
                s.curr = back;
                s.dir = reverse;
            }
        }
    }
}

//randomize the movement of the hunters
void moveHunter(Board& b){
    for(int i = 0; i < b.hunterCount; i++){
        Hunter& h = b.hunters[i];
        h.prev = h.curr;

        if(rand() % 2 == 0){ //track player
            int dc = b.player.col - h.curr.col;
            int dr = b.player.row - h.curr.row;
            if(abs(dc) >= abs(dr)){
                if(dc < 0) h.dir = 3;
                else if(dc > 0) h.dir = 1;
            }
            else{
                if(dr < 0) h.dir = 0;
                else if(dr > 0) h.dir = 2;
            }
        }

        Pos next = step(h.curr, h.dir);
        if(b.Board[next.row][next.col] == ' ')
            h.curr = next;
        else { //bounce function for hunters
            int reverse = turn(h.dir, 180);
            Pos back = step(h.curr, reverse);
            if(b.Board[back.row][back.col] == ' '){
                h.curr = back;
                h.dir = reverse;
            }
        }
    }
}
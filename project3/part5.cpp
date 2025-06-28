/**********
Filename: part5.cpp
Author: Zita Huang (m272898)
Project 3 Part 5
**********/
#include <iostream>
#include <fstream>
#include <unistd.h>
#include <ctime>
using namespace std;
#include "board.h"
#include "Pos.h"
#include "easycurses.h"

    int main(){
        //prompt user for board
        string filename;
        cout << "board file: ";
        cin >> filename; //enter in board

        Board b;
        if(!printBoard(filename, b)){
            cout << "File not found" << endl;
            return 1;
        }

        startCurses();
        int steps = 0;

        while(true){
            //draw the board
            for(int i = 0; i < b.row; i++){
                for(int j = 0; j < b.col; j++){
                    drawChar(b.Board[i][j], i, j);
                }
            }

            //drawing the ships
            for(int i = 0; i < b.shipCount; i++){
                drawChar ('*', b.ships[i].curr.row, b.ships[i].curr.col);
            }

            //drawinf the hunters
            for(int i = 0; i < b.hunterCount; i++){
                drawChar('K', b.hunters[i].curr.row, b.hunters[i].curr.col);
            }

            char x;
            if(b.immoral){
                x = 'I';
            }
            else{
                x = 'P';
            }
            drawChar(x, b.player.row, b.player.col);

            refreshWindow();
            usleep(100000);
            steps++; //count the steps for scoring

            //determine collision as non-immoral
            moveShip(b);
            moveHunter(b);
            
            if(!b.immoral && collision(b)){
                usleep(1000000);
                endCurses();
                cout << "You lose, they got you!" << endl;
                return 0;
            }

            //arrow key controls
            int kb = inputChar();
            if(kb == KEY_LEFT){
                b.pdir = turn(b.pdir, -90);
                b.moving = true;
            }
            else if(kb == KEY_RIGHT){
                b.pdir = turn(b.pdir, 90);
                b.moving = true;
            }
            else if(kb == KEY_UP){
                b.pdir = turn(b.pdir, 180);
                b.moving = true;
            }
            else if(kb == KEY_DOWN){
                b.pdir = turn(b.pdir, -180);
                b.moving = true;
            }
            else if(kb == 'r'){
                b.moving = false;
            }
            else if(kb == ' '){
                b.immoral = !b.immoral;
            }

            b.playerPrev = b.player;

            //determine if P is moving
            if(b.moving){
                Pos next = step(b.player, b.pdir);
                if(b.Board[next.row][next.col] == ' '){
                    b.player = next;
                }
                else{
                int reverse = turn(b.pdir, 180);
                Pos bounce = step(b.player, reverse);
                if(b.Board[bounce.row][bounce.col] == ' '){
                    b.pdir = reverse;
                    b.player = bounce;
                }
                }
            }

            //when near X exit the program, return to terminal
            if(reachGoal(b))
                break;
            //determine collision as immoral
            if(b.immoral && collision(b)){
                usleep(1000000);
                endCurses();
                cout << "You lost, they got you!" << endl;
                return 0;
            }
        }

        endCurses();
        
        //calculate the score
        int score = 500 - steps;
        if(score < 0)
            score = 0;

        cout << "Player start: (" << b.player.row << ","
             << b.player.col << ")\n";
        cout << "Spawn spots : ";
        for(int i = 0; i < b.ztotal; i++){
            cout << "(" << b.spawn[i].row << "," << b.spawn[i].col
                 <<")";
        }
        cout << endl;
        //output the score
        cout << "Score: " << score << endl;

        return 0;
    }
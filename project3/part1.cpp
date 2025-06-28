/**********
Filename: part1.cpp
Author: Zita Huang (m272898)
Project 3 Part 1
**********/
#include <iostream>
#include <fstream>
#include <unistd.h>
using namespace std;
#include "board.h"
#include "Pos.h"
#include "easycurses.h"

    int main(){
        //getting the filename 
        string filename;
        cout << "board file: ";
        cin >> filename;

        Board b;

        //error code if file is not found
        if(!printBoard(filename, b)){
            cout << "File not found" << endl;
            return 1;
        }

        startCurses();
        
        //draw the board out
        for(int i = 0; i < b.row; i++){
            for(int j = 0; j < b.col; j++){
                drawChar(b.Board[i][j], i, j);
            }
        }
        
        refreshWindow();

        //given loop to implement
        int kb = 'n';
        while(kb != 'y'){
            usleep(100000);
            kb = inputChar();
        }

        endCurses();

        //print out the player start coordinate
        cout << "Player start: (" << b.player.row << "," << b.player.col
             << ")" << endl;
        //print out the spawn spot coordinate
        cout << "Spawn spots : ";
        //for loop to calculate the spawn point
        for(int i = 0; i < b.ztotal; i++) {
            cout << "(" << b.spawn[i].row << "," << b.spawn[i].col << ") ";
        }
        cout << endl;


        return 0;
    }
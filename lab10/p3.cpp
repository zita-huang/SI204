/*********
Filename: p2.cpp
Author: Zita Huang (m272898)
Lab 10 Part 3
*********/
#include <iostream>
#include <unistd.h>
#include <cstdlib>
#include "easycurses.h"
using namespace std;

    struct charObj {
        char ch;
        int row, col;
    };

    //function for calculating the column movement 
    charObj move(charObj x, int dRow, int dCol){
            x.row += dRow;
            x.col += dCol;
            return x;    
        }

    int main(){
        int num;
        cin >> num;

        charObj chars[num];

        for(int i = 0; i < num; i++){
            char ch, junk;
            int row, col;
            cin >> ch >> junk >> row >> junk >> col >> junk;
            chars[i].ch = ch;
            chars[i].row = row;
            chars[i].col = col;

        }

        startCurses();

        //draw the characters onto the window
        for (int i = 0; i < num; i++) {
        drawChar(chars[i].ch, chars[i].row, chars[i].col);
        }
        //refresh the window to show the characters
        refreshWindow();
        usleep(80000);

        //movement phase
        for (int frame = 0; frame < 20; frame++) {
            //erase the last printed out characters from window
            for (int i = 0; i < num; i++) {
                drawChar(' ', chars[i].row, chars[i].col);
            }
            //calculate the next place of the character in column
            for (int i = 0; i < num; i++) {
                chars[i] = move(chars[i], 0, 1);
            }
            //draw out the character in its new spot
            for (int i = 0; i < num; i++) {
                drawChar(chars[i].ch, chars[i].row, chars[i].col);
            }
            //refresh the window to show the character
            refreshWindow();
            usleep(80000);

        //identify to quit if q is clicked 
        char c = inputChar();
        if(c == 'q')
            break;
        }

        endCurses();
        return 0;
    }
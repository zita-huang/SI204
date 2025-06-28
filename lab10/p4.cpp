/*********
Filename: p4.cpp
Author: Zita Huang (m272898)
Lab 10 Part 4
*********/
#include <iostream>
#include <unistd.h>
#include <cstdlib>
#include "easycurses.h"
using namespace std;

    struct charObj {
        char ch;
        int row, col;
        char direction;//create a direction(N, S, W, E)
    };

    //function for calculating the movement
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
            //create random direction for each character
            int initialDir = rand() % 4;
            if (initialDir == 0) 
                chars[i].direction = 'E';
            else if (initialDir == 1) 
                chars[i].direction = 'W';
            else if (initialDir == 2) 
                chars[i].direction = 'S';
            else 
                chars[i].direction = 'N';
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

            // Determine the new direction for each character before moving
            for (int i = 0; i < num; i++) {
                if (rand() % 5 == 0) { //Probability 1/5 to turn
                    int r = rand() % 2;
                    if (chars[i].direction == 'E' || chars[i].direction == 'W') { // Currently horizontal
                        if (r == 0) 
                            chars[i].direction = 'S';
                        else 
                            chars[i].direction = 'N';
                    } else { //Currently vertical (N or S)
                        if (r == 0) 
                            chars[i].direction = 'E';
                        else 
                            chars[i].direction = 'W';
                    }
                }
            }

            //Calculate the next position based on the determined direction
            for (int i = 0; i < num; i++) {
                if (chars[i].direction == 'E') {
                    chars[i] = move(chars[i], 0, 1);
                } else if (chars[i].direction == 'W') {
                    chars[i] = move(chars[i], 0, -1);
                } else if (chars[i].direction == 'S') {
                    chars[i] = move(chars[i], 1, 0);
                } else if (chars[i].direction == 'N') {
                    chars[i] = move(chars[i], -1, 0);
                }
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
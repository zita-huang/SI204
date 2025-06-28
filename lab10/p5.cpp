/*********
Filename: p5.cpp
Author: Zita Huang (m272898)
Lab 10 Part 5
*********/
#include <iostream>
#include <unistd.h>
#include <cstdlib>
#include "easycurses.h"
using namespace std;

    struct charObj {
        char ch;
        int row, col;
        char direction; // To remember the current direction (N, S, E, W)
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
            // Initialize a random direction for each character
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

        //get the height and width of the terminal window
        int height, width;
        getWindowDimensions(height, width);

        //draw the characters onto the window
        for (int i = 0; i < num; i++) {
        drawChar(chars[i].ch, chars[i].row, chars[i].col);
        }
        //refresh the window to show the characters
        refreshWindow();
        usleep(80000);

        //movement phase
        while (true) {
            //erase the last printed out characters from window
            for (int i = 0; i < num; i++) {
                drawChar(' ', chars[i].row, chars[i].col);
            }

            // Determine the new direction for each character
            for (int i = 0; i < num; i++) {
                if (rand() % 5 == 0) { //Probability 1/5 to turn
                    int r = rand() % 2;
                    if (chars[i].direction == 'E' || chars[i].direction == 'W') { // Currently horizontal
                        if (r == 0) chars[i].direction = 'S';
                        else chars[i].direction = 'N';
                    } else { // Currently vertical (N or S)
                        if (r == 0) chars[i].direction = 'E';
                        else chars[i].direction = 'W';
                    }
                }
            }

            // Calculate the next potential position and handle boundary collisions
            for (int i = 0; i < num; i++) {
                int nextRow = chars[i].row;
                int nextCol = chars[i].col;

                if (chars[i].direction == 'E') 
                    nextCol++;
                else if (chars[i].direction == 'W') 
                    nextCol--;
                else if (chars[i].direction == 'S') 
                    nextRow++;
                else if (chars[i].direction == 'N') 
                    nextRow--;

                // Check for boundary collision
                if (nextRow < 0 || nextRow >= height || nextCol < 0 || nextCol >= width) {
                    // Reverse direction
                    if (chars[i].direction == 'N') 
                        chars[i].direction = 'S';
                    else if (chars[i].direction == 'S') 
                        chars[i].direction = 'N';
                    else if (chars[i].direction == 'E') 
                        chars[i].direction = 'W';
                    else if (chars[i].direction == 'W') 
                        chars[i].direction = 'E';
                } else {
                    chars[i].row = nextRow;
                    chars[i].col = nextCol;
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
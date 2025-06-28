/*********
Filename: p6.cpp
Author: Zita Huang (m272898)
Lab 10 Part 6
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
        //desired number of letters floating around
        int num_chars = 40;
        charObj chars[num_chars];//create an array using the number from above

        // Initialize multiple characters
        for(int i = 0; i < num_chars; i++){
            chars[i].ch = 'A' + (rand() % 26);//pull in random characters
            chars[i].row = rand() % 20;//randomize where they start(row)
            chars[i].col = rand() % 40;//randomize where they start(column)
            
            int initialDir = rand() % 4; // randomize where they go
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

        int height, width;
        getWindowDimensions(height, width);

        //draw the characters onto the window
        for (int i = 0; i < num_chars; i++) {
            drawChar(chars[i].ch, chars[i].row, chars[i].col);
        }
        //refresh the window to show the characters
        refreshWindow();
        usleep(80000);

        //movement phase
        while (true) {
            //erase the last printed out characters from window
            for (int i = 0; i < num_chars; i++) {
                drawChar(' ', chars[i].row, chars[i].col);
            }

            // Determine the new direction for each character
            for (int i = 0; i < num_chars; i++) {
                if (rand() % 5 == 0) { // Probability 1/5 to turn
                    int r = rand() % 2;
                    if (chars[i].direction == 'E' || chars[i].direction == 'W') { // Currently horizontal
                        if (r == 0) 
                            chars[i].direction = 'S';
                        else 
                            chars[i].direction = 'N';
                    } else { // Currently vertical (N or S)
                        if (r == 0) 
                            chars[i].direction = 'E';
                        else 
                            chars[i].direction = 'W';
                    }
                }
            }

            // Calculate the next potential position and handle boundary collisions
            for (int i = 0; i < num_chars; i++) {
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
            for (int i = 0; i < num_chars; i++) {
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
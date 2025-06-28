/*********
Filename: p2.cpp
Author: Zita Huang (m272898)
Lab 10 Part 2
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

    int main(){
        int num;
        cin >> num;

        charObj chars[num];

        //read in the input coordinates
        for(int i = 0; i < num; i++){
            char ch, junk;
            int row, col;
            cin >> ch >> junk >> row >> junk >> col >> junk;
            //assign each input to their respective array type
            chars[i].ch = ch;
            chars[i].row = row;
            chars[i].col = col;
        }

        startCurses();

        while(true){
            //draw out each character with a 0.8 second delay
            for(int i  = 0; i < num; i++){
                drawCharAndRefresh(chars[i].ch, chars[i].row, chars[i].col);
                usleep(800000);
            }
            
            //erase all characters at the same time
            for(int i  = 0; i < num; i++){
                drawChar(' ', chars[i].row, chars[i].col);
                usleep(0);
            }

            //refresh the window after the erase
            refreshWindow();
            usleep(800000);

        //identify if the user hits q for quit
        char c = inputChar();
        if(c == 'q')
            break;
        }

        endCurses();
        return 0;
    }
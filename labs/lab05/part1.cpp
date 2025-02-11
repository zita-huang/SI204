/*************
Filename: part1.cpp
Author: MIDN Zita Huang (m272898)
Lab 5 Part 1(Board game)
*************/
#include<iostream>
#include<fstream>
#include<string>
using namespace std;

    int main()
    {
        string board;
        cin >> board;

        //Check to see that entry is valid
        ifstream fin(board);
        if (!fin)
        {
            cout << "File not found!" << endl;
            return 1;
        } 

        //string the width because it does not need to be read
        //int the position so that it can read it
        string space;
        int width, pos;
        fin >> space >> space >> width;
        cout << "Enter position between 1 and " << width << ": ";
        cin >> pos;

        //If statement for the boundaries of the position
        if(pos < 1 || pos > width)
        {
            cout << "Invalid position!" << endl;
            return 1;
        }

        //Output the board type
        //Use while loop to see if there is an X in the inputted position
        //count the step in the while loop outside the if statement
        string line;
        getline(fin, line);
        int step = 1;
        while(getline(fin, line))
        {
            if(line[pos] == 'X')
            {
                cout << "You died on step " << step << endl;
                return 0;
            }
            step++;
        }
        cout << "You survived!" << endl;
        return 0;
    }
/*************
Filename: part1.cpp
Author: MIDN Zita Huang (m272898)
Lab05 Part1
*************/
#include<iostream>
#include<fstream>
#include<string>
using namespace std;

    int main()
    {
        string board;
        cin >> board;

        ifstream fin(board);
        if (!fin)
        {
            cout << "File not found!" << endl;
            return 1;
        } 

        string width, equal;
        int num, pos, row, column;
        fin >> width >> equal >> num;
        cout << "Enter position between 1 and " << num << ": ";
        cin >> pos;
        if(pos > num)
        {
            cout << "Invalid position!" << endl;
            return 1;
        }
        else
        {
            string type;
            while(getline(fin, type))
            {
                if(pos = "X")
                {
                    cout << "died" << endl;
                }
                else 
                    cout << "survived" << endl;
            }
        }
       



        return 0;
    }
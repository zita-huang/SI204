/*****************
File name: hw.cpp
Author: MIDN Zita Huang (m272898)
Homework 12
****************/
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

    int main()
    {
       string filename;
       cout << "Filename: ";
       cin >> filename;

       ifstream fin(filename)
       if(!fin)
       {
        cout << "File does not exist!" << endl;
        return 1;
       }

       int row, column;
       fin >> row >> column;

       int table[row][column];

       for(int i = 0; i < row; i++)
       {
            for(int j = 0; j < cloumn; j++)
            {
                
            }
       }

        return 0;
    }
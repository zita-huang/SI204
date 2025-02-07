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
       //input the filename
       string filename;
       cout << "Filename: ";
       cin >> filename;

       ifstream fin(filename);
       if (!fin)
       {
        cout << "File not found" << endl;
        return 1;
       }

       int row, column;
       fin >> row >> column;

        //making the table
        //Used W3 schools as a reference to make table
       int table[row][column];

        //for loops to calculate the number of rows and columns
       for(int i = 0; i < row; i++)
       {
            for(int j = 0; j < column; j++)
            {
                fin >> table[i][j];
            }
       }

        //create the output file in html
        //create the border number for the table
       ofstream fout("output.html");
       fout << "<table border=2>\n";

       //for loop to generate the table in output.html
       for(int i = 0; i < row; i++)
       {
            fout << "<tr>";
            for(int j = 0; j < column; j++)
            {
                fout << "<td>" << table[i][j] << "</td>";
            }
            fout << "</tr>\n";
       }
       fout << "</table>\n";
       cout << "Created output.html" << endl;
        return 0;
    }
/*******************
Filename: readppm.cpp
Author: MIDN Zita Huang (m272898)
Project 1 p1
********************/
//Had help from MGSP leader!
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() 
{
    string filename;
    cout << "Input file: ";
    cin >> filename;
    
    ifstream fin(filename);

    //If file is not .ppm format will print this
    string header;
    fin >> header;
    if (header != "P3") {
        cout << "File not in .ppm format" << endl;
        return 1;
    }
    
    int width, height, max;
    fin >> width >> height >> max;
    
    cout << "P3" << endl;
    cout << "width = " << width << ", height = " << height << endl;
    cout << "max value = " << max << endl;
    
    //For loops to get the height, row, and column
    for (int i = 0; i < height; i++) 
    {
        cout << "*** row " << i << " ***" << endl;
        for (int j = 0; j < width; j++) 
        {
            int r, g, b;
            fin >> r >> g >> b;
            cout << "row " << i << ", col " << j << ": "
                 << "r" << r << " "
                 << "g" << g << " "
                 << "b" << b << endl;
        }
    }

    return 0;
}
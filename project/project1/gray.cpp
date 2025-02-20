/***************
Filename: gray.ppm
Author: MIDN Zita Huang (m272898)
Project1 Part2
***************/
//referenced lab 04 in making the output file
//Used class notes off of website
//referred back to readppm.cpp for the gray scale
//used the tip listed on the project 1 guidance
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() 
{
    string finame, outname;
    cout << "Input file: ";
    cin >> finame;
    cout << "Output file: ";
    cin >> outname;
    
    ifstream fin(finame);
    //print the error message if the input file is invalid
    if (!fin) {
        cout << "Error: Input file not found" << endl;
        return 1;
    }
    
    //print the output file
    ofstream fout(outname);
    
    //string the P3 to check for formatting
    string header;
    fin >> header;
    if (header != "P3") {
        cout << "File not in .ppm format" << endl;
        return 1;
    }
    fout << header << endl;
    
    int width, height, maxValue;
    fin >> width >> height >> maxValue;
    fout << width << " " << height << endl;
    fout << maxValue << endl;
    
    //for loops to convert to gray scale, by using average
    for (int i = 0; i < height; i++) 
    {
        for (int j = 0; j < width; j++) 
        {
            int r, g, b;
            fin >> r >> g >> b;
            int gray = (r + g + b) / 3; // Compute grayscale value
            fout << gray << " " << gray << " " << gray << " ";
        }
        fout << endl;
    }
    cout << "Image saved to " << outname << endl;
  
    return 0;
}



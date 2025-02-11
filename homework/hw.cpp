/*****************
File name: hw.cpp
Author: MIDN Zita Huang (m272898)
Homework 12
****************/
#include <iostream>
using namespace std;

    int main()
    {
        //get user input on width, height, and offset
        int width, height, offset;
        cout << "Enter height (greater than 2): ";
        cin >> height;
        cout << " Enter width (greater than 2): ";
        cin >> width;
        cout << "Enter offset: ";
        cin >> offset;

        //for loop for the height
        for (int i = 0; i < height; i++) 
        {
            //for loop to display the offset
            //for loop to display the * not in offset
            for (int j = 0; j < offset; j++) cout << ' ';
            for (int j = 0; j < width; j++) 
            {
                //If statement to determine the * and blank spots
                if (i == 0 || i == height - 1 || j == 0 || j == width - 1)
                    cout << '*';
                else
                    cout << ' ';
        }
        cout << endl;
    }

        return 0;
    }
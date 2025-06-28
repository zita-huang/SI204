/**********
Filename: p2.cpp
Author: Zita Huang (m272898)
Lab 2: Part 2
**********/

#include <iostream>
using namespace std;

    int main()
    {
        //Prompt the User to enter in a decimal number
        cout << "Enter a number between 0 and 15: ";
        int d1;
        cin >> d1;

        //Conversion from decimal to binary
        bool x, x1, x2, x3;
        x = (d1/1)%2;
        x1 = (d1/(2)%2);
        x2 = (d1/(2*2)%2);
        x3 = (d1/(2*2*2)%2);

        //The end result
        cout << d1 << " in binary is " << x3 << x2 << x1 << x << endl;

        return 0;
    }
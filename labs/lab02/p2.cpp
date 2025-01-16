/**********
Filename: p2.cpp
Author: Zita Huang (m272898)
Lab 2: Part 2
**********/

#include <iostream>
#include <cmath>
using namespace std;

    int main()
    {
        cout << "Enter a number between 0 and 15: ";
        int d1;
        cin >> d1;

        bool b1, b2, b3, b4;
        b1 = (d1/1);
        b2 = (d1/2);
        b3 = (d1/4);
        b4 = (d1/8);

        cout << d1 << " in binary is " << b1 << b2 << b3 << b4 << endl;

        return 0;
    }
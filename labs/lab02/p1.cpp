/************
Filename: p1.cpp
Author: Zita Huang (m272898)
Lab 2: Part 1
************/

#include <iostream>
#include<cmath>
using namespace std;

    int main()
    {
        //Prompt the user to enter in a 4-bit binary number
        cout << "Enter a 4-bit binary number: ";
        char b1, b2, b3, b4;
        cin >> b1 >> b2 >> b3 >> b4;

        
        //In between math(went from ASCII CHAR to DEC)
        char dn, dn1, dn2, dn3;
        dn = (b1-48)*8;
        dn1 = (b2-48)*4;
        dn2 = (b3-48)*2;
        dn3 = (b4-48)*1;

        //Add up the number represented by the bit
        int an;
        an = dn + dn1 + dn2 + dn3;
        
        //End result
        cout << "In decimal " << b1 << b2 << b3 << b4 << " = " << an << endl;

        return 0;
    }
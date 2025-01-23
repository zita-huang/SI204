/*****************
File name: hw.cpp
Author: MIDN Zita Huang (m272898)
Homework 6
****************/
#include <iostream>
#include <string>
#include <cmath>

using namespace std;

    int main()
    {
        //Initial prompt to user
        cout << "Values for a and b? ";
        double a, b, num;
        char c;
        cin >> a >> c >> b;
        
        //User input command to execute
        cout << "What do you want? ";
        string command;
        cin >> command;

        //If-else statement to decipher between squaring or adding
        if (command == "square")
        {
            //If-else if statement a or b to see which letter is being squared
            char letter;
            cin >> letter;
            if (letter == 'a')
            {
                a = a * a;
            }
            else if (letter == 'b')
            {
                b = b * b;
            }
        }
        else 
        {
            //Read the inputed command to include the reading of the integer
            //If-else if statement to see which letter is going to be added
            cin >> num >> command;
            if (command == "to")
            {
                char letter;
                cin >> letter;
                if (letter == 'a')
                {
                    a += num;
                }
                else if (letter == 'b')
                {
                    b += num;
                }
            }
        }
        
        //Display the end values of a and b
        cout << "a = " << a << " and b = " << b << endl;

        return 0;

    }
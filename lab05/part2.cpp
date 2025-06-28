/*************
Filename: part2.cpp
Author: MIDN Zita Huang (m272898)
Lab 5 Part 2(Fibonnaci)
*************/
#include <iostream>
using namespace std;

    int main()
    {
        int num1;

        //Program will run forever until 0
        while(true)
        {
            //get user input
            cout << "Enter total numbers in the Fibonacci series (0 to exit): ";
            cin >> num1;
            //if number entered is a 0, program will end
            if(num1 == 0)
            {
                cout << "Program terminated." << endl;
                return 1;
            }
        //Displaying results
         int n1 = 0, n2 = 1;
         cout << "Result: ";

        //For loop to do the calculations
        for(int i = 1; i <= num1; i++)
        {
            cout << n1 << " ";
            int nextnum1;
            nextnum1 = n1 + n2;
            n1 = n2;
            n2 = nextnum1;
        }
        cout << endl;
        }
   
        return 0;
    }
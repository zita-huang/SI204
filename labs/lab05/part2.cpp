/*************
Filename: part2.cpp
Author: MIDN Zita Huang (m272898)
Lab 5 Part 2(Fibonnaci)
*************/
#include <iostream>
using namespace std;

    int main()
    {
        int count;
        
        //Get user input on desired number
        int num1;
        cout << "Enter total numbers in the Fibonacci series (0 to exit): ";
        cin >> num1;

        if(num1 == 0)
        {
            cout << "Program terminated." << endl;
            return 1;
        }

         int n1 = 0, n2 = 1;
         cout << "Result: ";
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


        //If user enters 0, program will terminate

        //for loop to add the number consecutively with each other
        //update n1 to be n2, and n2 to be the sum of the n1 and n2
        //will continue until the number entered in the beginning is reached
         
        return 0;
    }